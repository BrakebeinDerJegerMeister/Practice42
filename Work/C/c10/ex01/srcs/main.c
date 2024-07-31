/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:13:06 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/31 11:28:30 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_putstr_ex(int std, char *str)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

int	disp_file(char *filename)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_ex(2, "Problème avec le fichier ");
		ft_putstr_ex(2, basename(filename));
		ft_putstr_ex(2, ", ");
		ft_putstr_ex(2, strerror(errno));
		ft_putstr_ex(2, "\n");
		return (1);
	}
	while (1)
	{
		bytes_read = read(fd, buffer, 1023);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		write(1, buffer, bytes_read);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret;
	int	i;

	ret = 0;
	if (argc < 2)
	{
		ft_putstr_ex(2, "Filename missing.\n");
		return (1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ret = disp_file(argv[i]);
			if (ret)
				return (1);
			i++;
		}
	}
	return (0);
}
