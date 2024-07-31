/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:56:43 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/31 23:11:11 by kaos             ###   ########.fr       */
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
		c1 = hex_digit((str[i] >> 4) & 0xF);
		c2 = hex_digit(str[i] & 0xF);
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

int	print_line(char *buffer, int addr, int bytes_read)
{
	int		i;
	char	c;

	print_addr(addr, "  ");
	print_hexstr(buffer, bytes_read);
	i = 0;
	if (bytes_read > 0)
		write(1, "  |", 3);
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
	return (0);
}

void	hexdump(int fd, char buffers[2][17], int bytes[2], int *same)
{
	int	i;

	i = 0;
	while (1)
	{
		copy_16(buffers[1], buffers[0]);
		bytes[1] = bytes[0];
		bytes[0] = read(fd, buffers[0], 16);
		if (bytes[0] <= 0)
			print_addr(16 * (i - (i > 0)) + bytes[1], "\n");
		if (bytes[0] <= 0)
			break ;
		buffers[0][bytes[0]] = '\0';
		if (is_equal_16(buffers[0], buffers[1]))
		{
			if (*same == 0)
				write(1, "*\n", 2);
			if (*same == 0)
				*same = 1;
		}
		else
			*same = print_line(buffers[0], 16 * i, bytes[0]);
		i++;
	}
}

int	read_file(char *filename)
{
	int		fd;
	int		same;
	int		bytes[2];
	char	buffers[2][17];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	bytes[0] = 0;
	bytes[1] = 0;
	same = 0;
	hexdump(fd, buffers, bytes, &same);
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*filename;

	filename = NULL;
	if (argc != 3)
	{
		putstr_err("Wrong number of arguments.\n");
		return (1);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == '\0')
		filename = argv[2];
	if (argv[2][0] == '-' && argv[2][1] == 'C' && argv[2][2] == '\0')
		filename = argv[1];
	if (filename == NULL)
	{
		putstr_err("Wrong option.\n");
		return (1);
	}
	if (read_file(filename))
	{
		putstr_err(basename(filename));
		putstr_err("error : ");
		putstr_err(strerror(errno));
		putstr_err("\n");
	}
	return (0);
}
