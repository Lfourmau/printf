/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:08:03 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/13 15:47:23 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_free_struct(t_struct *ptr_struct)
{
	int return_val;

	return_val = ptr_struct->return_val;
	free(ptr_struct);
	return (return_val);
}

int	ft_printf(const char *format, ...)
{
	char		*cursor;
	va_list		ap;
	t_struct	*ptr_struct;

	if (!(ptr_struct = malloc(sizeof(t_struct))))
		return (-1);
	ptr_struct->return_val = 0;
	va_start(ptr_struct->ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			ft_putchar_fd(*format, 1);
			format++;
			ptr_struct->return_val++;
		}
		if (*format)
		{
			struct_init(ptr_struct);
			cursor = parse_total((char *)format, ptr_struct);
			convert_all(ptr_struct);
			format = cursor;
		}
	}
	va_end(ap);
	return (ft_free_struct(ptr_struct));
}
