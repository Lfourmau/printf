/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:08:03 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 13:49:28 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_free_struct(t_struct *ts)
{
	int return_val;

	return_val = ts->return_val;
	free(ts);
	return (return_val);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*ts;

	if (!(ts = malloc(sizeof(t_struct))))
		return (-1);
	ts->return_val = 0;
	va_start(ts->ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			ft_putchar_fd(*format, 1);
			format++;
			ts->return_val++;
		}
		if (*format)
		{
			struct_init(ts);
			format = parse_total((char *)format, ts);
			convert_all(ts);
		}
	}
	va_end(ap);
	return (ft_free_struct(ts));
}
