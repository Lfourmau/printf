/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:08:03 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/29 14:43:40 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *toprint, ...)
{
	va_list ap;

	va_start(ap, toprint);
	parse_total(const char *, t_struct *ptr);

	if (t_struct->spec == 'spec')//check le spec dans la struct pour bien typer le prochain arg ?
		type nb = va_arg(ap, type); 

		convert_all(argument, t_struct *ptr);
		app_flags(t_struct *ptr);
		final_print();

	va_end(ap);
}
