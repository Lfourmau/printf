/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:44:02 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 13:33:43 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_init(t_struct *ts)
{
	ts->toprint = 0;
	ts->toprint_len = 0;
	ts->flags[0] = 0;
	ts->flags[1] = 0;
	ts->flags[2] = 0;
	ts->width = 0;
	ts->precision = 0;
	ts->spec = 0;
	ts->nbzero = 0;
	ts->nbspaces = 0;
	ts->neg = 0;
}
