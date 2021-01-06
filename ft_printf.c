/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:08:03 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/06 15:01:49 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	printf("pre-check\n");
	va_list ap;
	t_struct	*ptr_struct;
	printf("check1\n");	
	if (!(ptr_struct = malloc(sizeof(t_struct))))
		return (-1);
//	struct_init(ptr_struct);//segfault
	printf("check2\n");	
	va_start(ptr_struct->ap, format);
	printf("check3\n");	
	parse_total((char *)format, ptr_struct);
	printf("check4\n");	
	convert_all(ptr_struct);
	printf("check5\n");	
	final_print(ptr_struct); //boucle inf
	va_end(ap);

	return (1);
}
