/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:56:43 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/31 13:05:27 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_hexstr(char *str, int bytes_read)
{
	int		i;
	int		size;
	char	c1;
	char	c2;

	i = 0;
	size = 16;
	while (i < bytes_read)
	{
		c1 = HEX_DIGIT((str[i] >> 4) & 0xF);
		c2 = HEX_DIGIT(str[i] & 0xF);
		write(1, &c1, 1);
		write(1, &c2, 1);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
	while (i++ < size)
	{
		if (i == 6)
			write(1, " ", 1);
		write(1, "   ", 3);
	}
	write(1, " ", 1);
}

void	print_hexaddr(int addr)
{
	int					sz;
	char				disp;

	sz = 8;
	while (--sz >= 0)
	{
		disp = HEX_DIGIT((addr >> (4 * sz)) & 0xF);
		write(1, &disp, 1);
	}
	write(1, "  ", 2);
}

void	print_line(char *buffer, int addr, int bytes_read)
{
	int		i;
	char	c;

	print_hexaddr(addr);
	print_hexstr(buffer, bytes_read);
	i = 0;
	if (bytes_read > 0)
		write(1, "|", 1);
	while (i < bytes_read)
	{
		c = buffer[i];
		if (c > 31 && c < 127)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
	if (bytes_read > 0)
		write(1, "|", 1);
	write(1, "\n", 1);
}

int	hexdump(char *filename)
{
	unsigned int	i;
	char			buffer[17];
	char			old_buffer[17];
	int				bytes_read;
	int				fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while (1)
	{
		old_buffer = buffer;
		bytes_read = read(fd, buffer, 16);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		print_line(buffer, i * 16, bytes_read);
		i++;
	}
	print_line(buffer, i * 16, 0);
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*filename;

	filename = NULL;
	if (argc != 3)
	{
		PUTSTR_ERR("Wrong number of arguments.\n");
		return (1);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == '\0')
		filename = argv[2];
	if (argv[2][0] == '-' && argv[2][1] == 'C' && argv[2][2] == '\0')
		filename = argv[1];
	if (filename == NULL)
	{
		PUTSTR_ERR("Wrong option.\n");
		return (1);
	}
	if (hexdump(filename))
	{
		PUTSTR_ERR(basename(filename));
		PUTSTR_ERR("error : ");
		PUTSTR_ERR(strerror(errno));
		PUTSTR_ERR("\n");
	}
	return (0);
}
