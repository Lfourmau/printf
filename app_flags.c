/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:01:33 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/06 15:04:43 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print_width_front(t_struct *ptr_struct)
{
	int i;

	i = 0;
	if (!(ptr_struct->flags[0]))
	{
		while (i <= ptr_struct->width - (ptr_struct->toprint_len))
		{
			if (!(ptr_struct->flags[1]))
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
			i++;
		}
	}
}

void	print_width_back(t_struct *ptr_struct)
{
	int i;

	i = 0;
	if ((ptr_struct->flags[0]))
	{
		while (i < ptr_struct->width - (ptr_struct->toprint_len))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
}
