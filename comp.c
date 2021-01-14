/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:11:07 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:38 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

int		ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

void	ft_lencmp(t_struct *ts)
{
	if (ts->width && ts->neg)
		ts->width = ts->width - ft_max(ts->toprint_len, ts->precision) - 1;
	else if (ts->width && ts->spec == 'p')
		ts->width = ts->width - ft_max(ts->toprint_len, ts->precision) - 2;
	else if (ts->width)
		ts->width = ts->width - ft_max(ts->toprint_len, ts->precision);
	if (ft_strchr("diouxXp", ts->spec) && ts->flags[2] && !ts->precision
		&& !ft_strncmp(ts->toprint, "0", 2))
	{
		if (ts->width)
			ts->width++;
		free(ts->toprint);
		ts->toprint = ft_strdup("");
		ts->toprint_len = 0;
	}
	else if (!ts->flags[2] && !ts->precision && ts->flags[1] && !ts->flags[0])
	{
		ts->flags[2] = 1;
		ts->precision = ts->width;
		ts->width = 0;
	}
	else if (ts->precision)
		ts->precision -= ts->toprint_len;
}
