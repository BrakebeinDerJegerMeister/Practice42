/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:16:50 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/05 12:57:20 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_ulonglong_number(unsigned long long nb)
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

void	put_ulonglong_number_to_hex(unsigned long long nb, int nbchars)
{
	char	disp;
	int		current;

	current = nb & 0xF;
	if (current > 9)
	{
		disp = current + 'a' - 10 ;
	}
	else
	{
		disp = current + '0';
	}
	nbchars--;
	if (nbchars)
		put_ulonglong_number_to_hex(nb >> 4, nbchars);
	write(1, &disp, 1);
}

void	print_hexaddr(void *addr)
{
	unsigned long long	l_addr;

	l_addr = (unsigned long long)addr;
	put_ulonglong_number_to_hex(l_addr, 16);
	write(1, ": ", 2);
}

/*void	print_hexstr(void *addr)
{
}

void	print_str(void *addr)
{
}*/

void	*ft_print_memory(void *addr/*, unsigned int size*/)
{
	/*unsigned long long	l_addr;

	l_addr = (unsigned long long)addr;*/
	unsigned int	i;
	char		*str[17];

	i = 0;
	while (i <= size)
	{
		str[i % 16] = addr[i];
		if (!((i + 1) % 16))
		{
			print_hexstr(str);
			print_str(str);
			write(1, "\n", 1);
		}

	}
	

	print_hexaddr(addr);
	return addr;
}

int	main(void)
{
	int			*addr;
        unsigned long long      l_addr;


	char	str[] = "Bonjour les aminches"
		"\x09\x0a\x09"
		"c  est fou\x09tout\x09"
		"ce qu on peut faire avec\x09\x0a\x09print_memory\x0a\x0a\x0a\x09lol\x2elol\x0a i\n";
	
	addr = ft_print_memory(str, 48);
        l_addr = (unsigned long long)addr;
	write(1, "\n", 1);
	put_ulonglong_number(l_addr);
	write(1, "\n", 1);
	return (0);
}
