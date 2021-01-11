/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/11 13:20:14 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char toprint_c) //pour afficher char
{
	ft_putchar_fd(toprint_c, 1);
}

void	print_string(t_struct *ptr_struct) //pour afficher str
{
	int i;

	i = 0;
	if (ptr_struct->precision)
	{
		while (i < ptr_struct->precision && ptr_struct->toprint[i])
		{
		//	printf("|>>%d<< [%d] {%d}|", ptr_struct->return_val, ptr_struct->toprint[i], i);
			ft_putchar_fd(ptr_struct->toprint[i], 1);
			ptr_struct->return_val++;
			i++;
		}
	}
	else
	{
		ft_putstr_fd(ptr_struct->toprint, 1);
		ptr_struct->return_val += ptr_struct->initial_len;
	}
}

void	final_print(t_struct *ptr_struct)
{
	print_width_front(ptr_struct);
	if (ptr_struct->spec == 'p')
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		ptr_struct->return_val += 2;
		ptr_struct->toprint_len += 2;
	}
	if (ptr_struct->spec == 'c')
	{
		print_c(ptr_struct->toprint_c);
		ptr_struct->return_val++;
	}
	else
		print_string(ptr_struct);
	print_width_back(ptr_struct);
}
