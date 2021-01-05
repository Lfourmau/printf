/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:08:03 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 13:26:27 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *toprint, ...)
{
	va_list ap;

	va_start(ap, toprint);
	t_struct->ap = &ap;
	parse_total(const char *, t_struct *ptr);
	convert_all(argument, t_struct *ptr);
	app_flags(t_struct *ptr);
	final_print();
	//quand on aura le while, free toprint a la fin pour pas ecraser a chaque tour
	va_end(ap);
}
