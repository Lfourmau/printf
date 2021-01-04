/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/04 11:17:16 by lfourmau         ###   ########lyon.fr   */
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
	ft_putnbr_fd(1, ptr struct);
}

void	print_xX(t_struct *ptr)
{
	//afficher toprint xX car ce sont deux entiers hexa
}

void	final_print(t_struct *ptr)
{
	if (t_struct->spec == 'c')
		print_chars(ptr sur struct);
	if (t_struct->spec == 's')
		print_chars(ptr sur struct);
	if (t_struct->spec == 'p')
		print_p(ptr sur struct);
	if (t_struct->spec == 'd' || t_struct->spec == 'i' || t_struct->spec == 'u')
		print_diu(ptr sur struct);
	if (t_struct->spec == 'x' || t_struct->spec == 'X')
		print_xX(ptr sur struct);
}
