/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:47:30 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/31 11:47:14 by profchaos        ###   ########.fr       */
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

# define PUTSTR_ERR(S) { char *s = (S); while (*s) write(2, s++, 1); }

# define HEX_DIGIT(NIBBLE) ((NIBBLE) + '0' + ((NIBBLE) > 9) * 39)


#endif
