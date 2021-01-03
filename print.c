/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/29 14:43:38 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_chars(char *toprint) //pour afficher char et str
{
	while (*toprint)
	{
		ft_putchar_fd(toprint);
		toprint++;			
	}
}

void	print_p(t_struct *ptr)
{
	//afficher toprint
}

void	print_d(t_struct *ptr)
{
	//afficher un int --> Putnbr
}

void	print_i(t_struct *ptr)
{
	//afficher toprint
}

void	print_u(t_struct *ptr)
{
	//afficher toprint
}

void	print_x(t_struct *ptr)
{
	//afficher toprint
}

void	print_X(t_struct *ptr)
{
	//afficher toprint
}
i

void	final_print(t_struct *ptr)
{
	if (t_struct->spec == 'c')
		print_chars(ptr sur struct);
	if (t_struct->spec == 's')
		print_chars(ptr sur struct);
	if (t_struct->spec == 'p')
		print_p(ptr sur struct);
	if (t_struct->spec == 'd')
		print_d(ptr sur struct);
	if (t_struct->spec == 'i')
		print_i(ptr sur struct);
	if (t_struct->spec == 'u')
		print_u(ptr sur struct);
	if (t_struct->spec == 'x')
		print_x(ptr sur struct);
	if (t_struct->spec == 'X')
		print_X(ptr sur struct);
}
