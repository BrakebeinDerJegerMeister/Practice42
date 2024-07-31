/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:47:30 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/31 22:58:14 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

void	print_addr(int addr, char *next);
char	hex_digit(char c);
void	putstr_err(char *str);
void	copy_16(char *s1, char *s2);
int		is_equal_16(char *s1, char *s2);

#endif
