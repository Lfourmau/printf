/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 13:26:22 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char *toprint) //pour afficher char
{
		ft_putchar_fd(1, toprint);
}

void	print_s(char *toprint) //pour afficher str
{
		ft_putstr_fd(1, toprint);
}
void	print_p(t_struct *ptr)
{
	//afficher toprint
}

void	print_diu(t_struct *ptr)
{
	ft_putstr_fd(1, t_struct->toprint);
}

void	print_xX(t_struct *ptr)
{
	ft_putstr_fd(1, t_struct->toprint);
}

void	final_print(t_struct *ptr)
{
	if (t_struct->spec == 'c')
		print_c(ptr sur struct);
	if (t_struct->spec == 's')
		print_chars(ptr sur struct);
	if (t_struct->spec == 'p')
		print_p(ptr sur struct);
	if (t_struct->spec == 'd' || t_struct->spec == 'i' || t_struct->spec == 'u')
		print_diu(ptr sur struct);
	if (t_struct->spec == 'x' || t_struct->spec == 'X')
		print_xX(ptr sur struct);
}
