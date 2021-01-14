/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displ_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:08:21 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 11:12:39 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_displ_spc(t_struct *ts, int i)
{
	if (ts->spec == 'c' && ts->toprint_c == 0)
		i--;
	while (0 < i)
	{
		ft_putchar_fd(' ', 1);
		ts->return_val++;
		i--;
	}
}

void	ft_displ_zero(t_struct *ts, int i)
{
	while (0 < i)
	{
		ft_putchar_fd('0', 1);
		ts->return_val++;
		i--;
	}
}

void	ft_displ_pre(t_struct *ts)
{
	if (ts->neg)
	{
		ft_putchar_fd('-', 1);
		ts->return_val++;
	}
	else if (ts->spec == 'p')
	{
		ft_putstr_fd("0x", 1);
		ts->return_val += 2;
	}
}
