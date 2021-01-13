/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:39:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/13 17:25:43 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	print_c(char toprint_c)
// {
// 	ft_putchar_fd(toprint_c, 1);
// }

// void	print_string(t_struct *ptr_struct)
// {
// 	int i;

// 	i = 0;
// 	if (ptr_struct->spec == 's')
// 	{
// 		if (ptr_struct->flags[2])
// 			while (i < ft_min(ptr_struct->toprint_len, ptr_struct->precision) && ptr_struct->toprint[i])
// 			{
// 				ft_putchar_fd(ptr_struct->toprint[i], 1);
// 				ptr_struct->return_val++;
// 				i++;
// 			}
// 		else
// 			while (i < ptr_struct->toprint_len && ptr_struct->toprint[i])
// 			{
// 				ft_putchar_fd(ptr_struct->toprint[i], 1);
// 				ptr_struct->return_val++;
// 				i++;
// 			}
// 	}
// 	else
// 	{
// 		while (ptr_struct->toprint[i])
// 		{
// 			ft_putchar_fd(ptr_struct->toprint[i], 1);
// 			ptr_struct->return_val++;
// 			i++;
// 		}
// 	}
// }

// void	final_print(t_struct *ptr_struct)
// {
// 	// printf("\nSpc : [%d]\n", ptr_struct->nbspaces);
// 	if (ptr_struct->flags[2] && !ptr_struct->precision && ft_isintspec(ptr_struct->spec) && !ft_strncmp("0", ptr_struct->toprint, 2))
// 		if (ptr_struct->width)
// 			ptr_struct->nbspaces++;
// 	else if (!ptr_struct->precision && !ptr_struct->flags[2] && !ptr_struct->flags[0] && ptr_struct->flags[1])
// 	{
// 		ptr_struct->nbzero = ptr_struct->nbspaces;
// 		ptr_struct->nbspaces = 0;
// 	}
// 	print_width_front(ptr_struct);
// 	if (ptr_struct->spec == 'p')
// 	{
// 		ft_putchar_fd('0', 1);
// 		ft_putchar_fd('x', 1);
// 		ptr_struct->return_val += 2;
// 		ptr_struct->toprint_len += 2;
// 	}
// 	if (ptr_struct->spec == 'c' || ptr_struct->spec == '%')
// 	{
// 		print_c(ptr_struct->toprint_c);
// 		ptr_struct->return_val++;
// 	}
// 	else
// 		print_string(ptr_struct);
// 	print_width_back(ptr_struct);
// 	free (ptr_struct->toprint);
// }

void	ft_displ_spc(t_struct *ts, int i)
{
	while (0 < i)
	{
		ft_putchar_fd(' ', 1);
		ts->return_val++;
		i--;
	}
}

void	ft_displ_zero(t_struct *ts, int i)
{
	while (0 < i)
	{
		ft_putchar_fd('0', 1);
		ts->return_val++;
		i--;
	}
}

void	ft_displ_pre(t_struct *ts)
{
	if (ts->neg)
	{
		ft_putchar_fd('-', 1);
		ts->return_val++;
	}
	else if (ts->spec == 'p')
	{
		ft_putstr_fd("0x", 1);
		ts->return_val += 2;
	}
}

void	ft_displ_int(t_struct *ts)
{
	if (!ts->flags[0] && ts->width)
		ft_displ_spc(ts, ts->width);
	ft_displ_pre(ts);
	if (ts->flags[2] && ts->precision)
		ft_displ_zero(ts, ts->precision);
	ft_putstr_fd(ts->toprint, 1);
	ts->return_val += ts->toprint_len;
	if (ts->flags[0])
		ft_displ_spc(ts, ts->width);
}

void	ft_displ_str(t_struct *ts)
{
	int i;

	i = 0;
	if (ts->width && !ts->flags[2])
		ts->width -= ts->toprint_len;
	else if (ts->width)
		ts->width -= ft_min(ts->precision, ts->toprint_len);
	if (ts->width && !ts->flags[0] && !ts->flags[1])
		ft_displ_spc(ts, ts->width);
	else if (ts->width && !ts->flags[0] && ts->flags[1])
		ft_displ_zero(ts, ts->width);
	if (ts->flags[2] && ts->spec == 's')
		while (i < ts->precision && ts->toprint[i])
		{
			ft_putchar_fd(ts->toprint[i], 1);
			ts->return_val++;
			i++;
		}
	else if (ts->spec == 's')
	{
		ft_putstr_fd(ts->toprint, 1);
		ts->return_val += ts->toprint_len;
	}
	else
	{
		if (ts->flags[2] && !ts->precision && ts->spec == 'c')
			ft_putstr_fd(0, 1);
		else
		{
			ft_putchar_fd(ts->toprint_c, 1);
			ts->return_val++;
		}
	}
	if (ts->flags[0])
		ft_displ_spc(ts, ts->width);
}
