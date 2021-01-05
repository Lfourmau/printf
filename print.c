/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 15:32:50 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char *toprint) //pour afficher char
{
		ft_putchar_fd(1, toprint);
}

void	print_string(char *toprint) //pour afficher str
{
		ft_putstr_fd(1, toprint);
}

void	final_print(t_struct *ptr_struct)
{
	if (t_struct->spec == 'c')
		print_c(ptr_struct->toprint);
	else
		print_string(ptr_struct->toprint);
}
