/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:08:03 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 15:32:55 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	t_struct	*ptr_struct;

	va_start(ap, format);
	t_struct->ap = &ap;
	parse_total(format, ptr_struct);
	convert_all(ptr_struct);
	app_flags(ptr_struct);
	final_print();
	//quand on aura le while, free toprint a la fin pour pas ecraser a chaque tour
	va_end(ap);
}
