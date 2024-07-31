/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:40:20 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/31 11:29:50 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int	get_option_c(char *str, char *nbr, int *num)
{
	int		nb;
	int		i;
	char	*conv;

	if (str[0] == '-' && str[1] == 'c')
	{
		if (str[2] == '\0')
			conv = nbr;
		else
		{
			str = str + 2;
			conv = str;
		}
		nb = 0;
		i = 0;
		while (conv[i] >= '0' && conv[i] <= '9')
		{
			nb = (int)conv[i] - 48 + nb * 10;
			i++;
		}
		*num = nb;
		return (1);
	}
	return (0);
}

int	get_filesize(char *filename)
{
	int		fd;
	char	buffer[1024];
	int		size;
	int		bytes_read;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, 1024);
		size = size + bytes_read;
		if (bytes_read <= 0)
			break ;
	}
	close(fd);
	return (size);
}

void	ft_putstr_ex(int std, char *str)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

int	tail(char *filename, int limit)
{
	int		fd;
	char	buffer[1];
	int		bytes_read;
	int		size;
	int		current;

	size = get_filesize(filename);
	fd = open(filename, O_RDONLY);
	if (size == -1)
	{
		return (1);
	}
	current = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, 1);
		current = current + bytes_read;
		if ((current + limit) >= size)
			write(1, buffer, 1);
		if (bytes_read <= 0)
			break ;
	}
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		num;
	char	*filename;

	if (argc < 4)
		ft_putstr_ex(2, "Too few arguments.\n");
	if (argc > 4)
		ft_putstr_ex(2, "Too many arguments.\n");
	if (argc != 4)
		return (1);
	if (get_option_c(argv[1], argv[2], &num))
		filename = argv[3];
	else if (get_option_c(argv[2], argv[3], &num))
		filename = argv[1];
	else
		return (1);
	if (tail(filename, num))
	{
		ft_putstr_ex(2, "File error : ");
		ft_putstr_ex(2, basename(filename));
		ft_putstr_ex(2, ", ");
		ft_putstr_ex(2, strerror(errno));
		ft_putstr_ex(2, "\n");
	}
	return (0);
}
