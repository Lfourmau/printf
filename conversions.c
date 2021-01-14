/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:39:06 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 18:43:11 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display(t_struct *ts)
{
	if (ft_isintspec(ts->spec) || ts->spec == 'p')
	{
		ft_lencmp(ts);
		ft_displ_int(ts);
	}
	else if (ts->spec == 's')
		ft_displ_str(ts);
	else
		ft_displ_char(ts);
}

void	convert_all(t_struct *ts)
{
	if (ts->spec == 'c')
		ts->toprint_c = va_arg(ts->ap, int);
	if (ts->spec == '%')
		ts->toprint_c = '%';
	if (ts->spec == 's')
		ts->toprint = ft_convert_s(va_arg(ts->ap, char *));
	if (ts->spec == 'p')
		ts->toprint = ft_convert_p(va_arg(ts->ap, void *));
	if (ts->spec == 'd' || ts->spec == 'i')
		ts->toprint = ft_convert_di(va_arg(ts->ap, int), ts);
	if (ts->spec == 'u')
		ts->toprint = ft_convert_u(va_arg(ts->ap, unsigned int));
	if (ts->spec == 'x' || ts->spec == 'X')
		ts->toprint = ft_convert_x(va_arg(ts->ap, unsigned int), ts);
	if (ts->toprint)
		ts->toprint_len += strlen(ts->toprint);
	else if (ts->toprint_c)
		ts->toprint_len = 1;
	if (!ts->toprint && !ft_strchr("c%", ts->spec))
		return ;
	ft_display(ts);
}
