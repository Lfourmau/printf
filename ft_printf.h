/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:10:08 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/11 15:21:05 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_struct
{
	va_list		ap;
	char		*toprint;
	char		toprint_c;
	int			toprint_len;
	int			initial_len;
	int			flags[5];
	int			width;
	int			precision;
	int			len_or_prec;
	int			min;
	int			max;
	int			nbspaces;
	int			nbzero;
	int			return_val;
	char		spec;
}				t_struct;

int			ft_printf(const char *format, ...);
void		print_width_front(t_struct *ptr_struct);
void		print_width_back(t_struct *ptr_struct);
void		convert_all(t_struct *ptr_struct);
int			ft_isflag(char c);
int			ft_isspec(char c);
int			ft_isintspec(char c);
char		*parse_total(char *toparse, t_struct *ptr_struct);
void		final_print(t_struct *ptr_struct);
void		struct_init(t_struct *ptr_struct);
#endif
