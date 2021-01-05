/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:01:33 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 15:32:45 by lfourmau         ###   ########lyon.fr   */
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

void	app_flags(t_struct *ptr_struct)
{
	if (ptr_struct->flags[0])
		ptr_struct->toprint = ft_moins(t_struct->toprint);
	if (ptr_struct->flags[1])
		ptr_struct->toprint = ft_zero(t_struct->toprint);
	if (ptr_struct->flags[2])
		ptr_struct->toprint = ft_space(t_struct->toprint);
	if (ptr_struct->flags[3])
		ptr_struct->toprint = ft_dieze(t_struct->toprint);
	if (ptr_struct->flags[4])
		ptr_struct->toprint = ft_plus(t_struct->toprint);
}
