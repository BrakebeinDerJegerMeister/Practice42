/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:16:50 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/05 19:34:08 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	nib_to_hexchar(int val)
{
	char	hex;

	if (val > 9)
		hex = val + 'a' - 10;
	else
		hex = val + '0';
	return (hex);
}

void	strprint_char_or_dot(char *str, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len)
	{
		c = str[i];
		if (c > 31 && c < 127)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_hexstr(char *str, int len)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (i < 16)
	{
		if (!(i % 2))
		{
			write(1, " ", 1);
		}
		if (i < len)
		{
			c1 = nib_to_hexchar(str[i] >> 4);
			c2 = nib_to_hexchar(str[i] & 0xF);
			write(1, &c1, 1);
			write(1, &c2, 1);
		}
		else
		{
			write(1, "  ", 2);
		}
		i++;
	}
	write(1, " ", 1);
}

void	print_hexaddr(char *addr)
{
	unsigned long long	l_addr;
	int					sz;
	char				disp;

	sz = 16;
	l_addr = (unsigned long long)addr;
	while (--sz >= 0)
	{
		disp = nib_to_hexchar((l_addr >> (4 * sz)) & 0xF);
		write(1, &disp, 1);
	}
	write(1, ":", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	int				len;
	char			*p_addr;

	p_addr = (char *)addr;
	k = 0;
	while (k < (1 + size / 16))
	{
		i = 0;
		len = 0;
		while (i < 16)
		{
			if ((k * 16 + i) < size)
				len++;
			i++;
		}
		print_hexaddr(p_addr + k * 16);
		print_hexstr(p_addr + k * 16, len);
		strprint_char_or_dot(p_addr + k * 16, len);
		write(1, "\n", 1);
		k++;
	}
	return (addr);
}

/*void	put_ulonglong_number(unsigned long long nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		put_ulonglong_number(nb);
	}
	write(1, &disp, 1);
}

int	main(void)
{
	int					*addr;
	unsigned long long	l_addr;
	char				str[] = "Bonjour les aminches"
		"\x09\x0a\x09"
		"c  est fou\x09tout\x09"
		"ce qu on peut faire avec\x09\x0a\x09print_memory\x0a\x0a\x0a\x09lol\x2elol\x0a \0";

	addr = ft_print_memory(str, 92);
	l_addr = (unsigned long long)addr;
	write(1, "\n", 1);
	put_ulonglong_number(l_addr);
	write(1, "\n", 1);
	return (0);
}*/
