/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:44:02 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/08 16:00:27 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_init(t_struct *ptr_struct)
{
	ptr_struct->toprint = 0;
	ptr_struct->toprint_len = 0;
	ptr_struct->flags[0] = 0;
	ptr_struct->flags[1] = 0;
	ptr_struct->width = 0;
	ptr_struct->precision = 0;
	ptr_struct->spec = 0;
}
