/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:45:26 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/02 11:07:19 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		add(int a, int b, int *err);
int		sub(int a, int b, int *err);
int		mul(int a, int b, int *err);
int		div(int a, int b, int *err);
int		mod(int a, int b, int *err);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int old_nb);
void	do_op(int a, int b, char *op);

#endif
