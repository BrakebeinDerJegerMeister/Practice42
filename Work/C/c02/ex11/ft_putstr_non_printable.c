/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:22:39 by kaos              #+#    #+#             */
/*   Updated: 2024/07/04 22:42:00 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char_to_hex(char c)
{
	char	c1;
	char	c2;

	c1 = 48 + (c >> 4);
	c2 = 48 + (c & 0xF);
	if (c2 > '9')
		c2 = c2 + 39;
	write(1, "\\", 1);
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c > 31 && c < 127)
		{
			write(1, &c, 1);
		}
		else
		{
			print_char_to_hex(c);
		}
		i++;
	}
}

/*void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	test(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
}

int	main(void)
{
	char	str1[] = "Coucou\ntu vas bien ?";
	char	str2[] = "Un \x13 \x07 essai \x16 \x25 \x48\x65\x6c\x6c\x6f";

	test(str1);
	test(str2);
	return (0);
}*/
