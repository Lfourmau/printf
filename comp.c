/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:11:07 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/13 18:02:11 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int nb1, int nb2)
{
	if (nb1 > nb2)
    	return (nb1);
	return (nb2);
}

int		ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
    	return (nb1);
	return (nb2);
}

// void    ft_nbzero(t_struct *ptr_struct)
// {
// 	int len_or_prec;

// 	len_or_prec = ft_max(ptr_struct->toprint_len, ptr_struct->precision);
// 	if (ft_isintspec(ptr_struct->spec))
// 	{
// 		if (ptr_struct->toprint_len < ptr_struct->precision)
// 			ptr_struct->nbzero = ptr_struct->precision - ptr_struct->toprint_len;		
// 	}
// 	else if (ptr_struct->spec == 'p')
// 		ptr_struct->nbzero = 0;
// 	else if (ptr_struct->spec == 's' || ptr_struct->spec == 'c')
// 		ptr_struct->nbzero = 0;
// }

// void    ft_nbspaces(t_struct *ptr_struct)
// {
// 	int len_or_prec;

// 	len_or_prec = ft_max(ptr_struct->toprint_len, ptr_struct->precision);
// 	if (ft_isintspec(ptr_struct->spec))
// 	{
// 		if (ptr_struct->width > len_or_prec)
// 			ptr_struct->nbspaces = ptr_struct->width - len_or_prec;
// 	}
// 	else if (ptr_struct->spec == 'p')
// 		ptr_struct->nbspaces = ptr_struct->width - ft_max(ptr_struct->toprint_len + 2, ptr_struct->precision);
// 	else if (ptr_struct->spec == 's' && ptr_struct->flags[2])
// 		ptr_struct->nbspaces = ptr_struct->width - ft_min(ptr_struct->toprint_len, ptr_struct->precision);
// 	else if (ptr_struct->spec == 's' && !ptr_struct->flags[2])
// 		ptr_struct->nbspaces = ptr_struct->width - ptr_struct->toprint_len;
// 	else if (ptr_struct->spec == 'c')
// 		ptr_struct->nbspaces = ptr_struct->width;
// 	if (ptr_struct->neg == 1)
// 		ptr_struct->nbspaces--;
// }

void	ft_lencmp(t_struct *ptr_struct)
{
	if (ptr_struct->width && ptr_struct->neg)
		ptr_struct->width = ptr_struct->width - ft_max(ptr_struct->toprint_len, ptr_struct->precision) - 1;
	else if (ptr_struct->width && ptr_struct->spec == 'p')
		ptr_struct->width = ptr_struct->width - ft_max(ptr_struct->toprint_len, ptr_struct->precision) - 2;
	else if (ptr_struct->width)
		ptr_struct->width = ptr_struct->width - ft_max(ptr_struct->toprint_len, ptr_struct->precision);
	if (ft_strchr("diouxXp", ptr_struct->spec) && ptr_struct->flags[2] && !ptr_struct->precision
		&& !ft_strncmp(ptr_struct->toprint, "0", 2))
	{
		if (ptr_struct->width)
			ptr_struct->width++;
		ptr_struct->toprint = "";
		ptr_struct->toprint_len = 0;
	}
	else if (!ptr_struct->flags[2] && !ptr_struct->precision && ptr_struct->flags[1] && !ptr_struct->flags[0])
	{
		ptr_struct->flags[2] = 1;
		ptr_struct->precision = ptr_struct->width;
		ptr_struct->width = 0;
	}
	else if (ptr_struct->precision)
		ptr_struct->precision -= ptr_struct->toprint_len;
}
