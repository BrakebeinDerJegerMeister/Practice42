/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:32:18 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/31 11:27:51 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	disp_file(char *filename)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
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

	ret = 0;
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc != 2)
		return (1);
	ret = disp_file(argv[1]);
	if (ret)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	return (0);
}
