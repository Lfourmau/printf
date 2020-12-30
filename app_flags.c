/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:01:33 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/29 14:39:28 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dieze(char *)
{

}

void	ft_moins(char *)
{

}

void	ft_zero(char *)
{

}

void	ft_plus(char *)
{

}

void	ft_space(char *)
{

}

void	app_flags(structure, t_struct *ptr)
{
	if (t_struct->flags[0])
		t_struct->toprint = ft_moins(t_struct->toprint);
	if (t_struct->flags[1])
		t_struct->toprint = ft_zero(t_struct->toprint);
	if (t_struct->flags[0])
		t_struct->toprint = ft_space(t_struct->toprint);
	if (t_struct->flags[0])
		t_struct->toprint = ft_dieze(t_struct->toprint);
	if (t_struct->flags[0])
		t_struct->toprint = ft_plus(t_struct->toprint);
}
