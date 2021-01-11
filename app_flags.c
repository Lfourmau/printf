/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:01:33 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/11 17:05:41 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	print_width_front(t_struct *ptr_struct)
{
	int i;
	i = 0;
	if (ptr_struct->flags[0] == 0)
	{
		while ((i < ptr_struct->width - (ptr_struct->toprint_len)) || (i < ptr_struct->precision - (ptr_struct->toprint_len)))
		{
			if (ptr_struct->flags[1] == 0 && ptr_struct->precision == 0)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
			i++;
		}
	}
}
*/
void	print_width_back(t_struct *ptr_struct)
{
	int i;

	i = 0;
	if (ptr_struct->spec == 'c')
		i++;
	if (ptr_struct->flags[0] == 1)
	{
		while (i < ptr_struct->nbspaces)
		{
			ft_putchar_fd(' ', 1);
			i++;
			ptr_struct->return_val++;
		}
	}
}

void	print_width_front(t_struct *ptr_struct)
{
	int i;

	i = 0;
	if (ptr_struct->spec == 'c')
		i++;
	while (i < ptr_struct->nbspaces && ptr_struct->flags[0] == 0)
	{
			ft_putchar_fd(' ', 1);
			ptr_struct->return_val++;
			i++;
	}
	i = 0;
	while (i < ptr_struct->nbzero)
	{
		ft_putchar_fd('0', 1);
		ptr_struct->return_val++;
		i++;
	}
}
