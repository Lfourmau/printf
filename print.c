/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 11:15:02 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_displ_str_util(t_struct *ts)
{
	int i;

	i = 0;
	if (ts->flags[2] && ts->spec == 's')
		while (i < ts->precision && ts->toprint[i])
		{
			ft_putchar_fd(ts->toprint[i], 1);
			ts->return_val++;
			i++;
		}
	else if (ts->spec == 's')
	{
		ft_putstr_fd(ts->toprint, 1);
		ts->return_val += ts->toprint_len;
	}
	if (ts->flags[0])
		ft_displ_spc(ts, ts->width);
}

void	ft_displ_str(t_struct *ts)
{
	if (ts->width && !ts->flags[2])
		ts->width -= ts->toprint_len;
	else if (ts->width)
		ts->width -= ft_min(ts->precision, ts->toprint_len);
	if (ts->width && !ts->flags[0] && !ts->flags[1])
		ft_displ_spc(ts, ts->width);
	else if (ts->width && !ts->flags[0] && ts->flags[1])
		ft_displ_zero(ts, ts->width);
	ft_displ_str_util(ts);
	free(ts->toprint);
}

void	ft_displ_int(t_struct *ts)
{
	if (!ts->flags[0] && ts->width)
		ft_displ_spc(ts, ts->width);
	ft_displ_pre(ts);
	if (ts->flags[2] && ts->precision)
		ft_displ_zero(ts, ts->precision);
	ft_putstr_fd(ts->toprint, 1);
	ts->return_val += ts->toprint_len;
	if (ts->flags[0])
		ft_displ_spc(ts, ts->width);
	//free(ts->toprint);
}

void	ft_displ_char(t_struct *ts)
{
	if (ts->width && !ts->flags[2])
		ts->width -= ts->toprint_len;
	else if (ts->width)
		ts->width -= ft_min(ts->precision, ts->toprint_len);
	if (ts->width && !ts->flags[0] && !ts->flags[1])
		ft_displ_spc(ts, ts->width);
	else if (ts->width && !ts->flags[0] && ts->flags[1])
		ft_displ_zero(ts, ts->width);
	if (ts->flags[2] && !ts->precision && ts->spec == 'c')
		ft_putstr_fd(0, 1);
	else
	{
		ft_putchar_fd(ts->toprint_c, 1);
		ts->return_val++;
	}
	if (ts->flags[0])
		ft_displ_spc(ts, ts->width);
}
