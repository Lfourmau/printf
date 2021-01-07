/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:08:03 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/07 14:06:59 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	char *cursor;
	va_list ap;
	t_struct	*ptr_struct;
	while (*format)
	{
		if (!(ptr_struct = malloc(sizeof(t_struct))))
			return (-1);
		struct_init(ptr_struct);
		va_start(ptr_struct->ap, format);
		cursor = parse_total((char *)format, ptr_struct);
		convert_all(ptr_struct);
		final_print(ptr_struct);
		format = cursor;
	}
		va_end(ap);
		return (1);
}
