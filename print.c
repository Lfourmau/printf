/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/06 13:51:32 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char toprint_c) //pour afficher char
{
		ft_putchar_fd(toprint_c, 1);
}

void	print_string(char *toprint) //pour afficher str
{
		ft_putstr_fd(toprint, 1);
}

void	final_print(t_struct *ptr_struct)
{
	print_width_front(ptr_struct);
	if (ptr_struct->spec == 'c')
		print_c(ptr_struct->toprint_c);
	else
		print_string(ptr_struct->toprint);
	
	print_width_back(ptr_struct);
}
