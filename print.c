/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/12 18:36:20 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char toprint_c)
{
	ft_putchar_fd(toprint_c, 1);
}

void	print_string(t_struct *ptr_struct)
{
	int i;

	i = 0;
	if (ptr_struct->spec == 's')
	{
		while (i < ft_min(ptr_struct->toprint_len, ptr_struct->precision) && ptr_struct->toprint[i])
		{
			ft_putchar_fd(ptr_struct->toprint[i], 1);
			ptr_struct->return_val++;
			i++;
		}
	}
	else
	{
		while (ptr_struct->toprint[i])
		{
			ft_putchar_fd(ptr_struct->toprint[i], 1);
			ptr_struct->return_val++;
			i++;
		}
	}
}

void	final_print(t_struct *ptr_struct)
{
	if (ptr_struct->width && ptr_struct->flags[2] == 0 && ptr_struct->flags[0] == 0 && ft_isintspec(ptr_struct->spec))
	{
		ptr_struct->nbzero = ptr_struct->nbspaces;
		ptr_struct->nbspaces = 0;
	}
	print_width_front(ptr_struct);
	if (ptr_struct->spec == 'p')
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		ptr_struct->return_val += 2;
		ptr_struct->toprint_len += 2;
	}
	if (ptr_struct->spec == 'c' || ptr_struct->spec == '%')
	{
		print_c(ptr_struct->toprint_c);
		ptr_struct->return_val++;
	}
	else if (!(ptr_struct->flags[2] == 1 && ptr_struct->precision == 0 && *ptr_struct->toprint == '0'))
		print_string(ptr_struct);
	print_width_back(ptr_struct);
}
