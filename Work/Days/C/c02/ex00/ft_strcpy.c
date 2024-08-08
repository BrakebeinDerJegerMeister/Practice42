/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:50:17 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/01 16:18:16 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (save);
}

/*void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char	src[] = "Hello 42";
	char	dest[9];
	char	*res;

	ft_putstr(src);
	write(1, "\n", 1);
	res = ft_strcpy(dest, src);
	ft_putstr(dest);
	write(1, "\n", 1);
	ft_putstr(res);
	write(1, "\n", 1);
}*/
