/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:10:08 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/07 09:08:26 by lfourmau         ###   ########lyon.fr   */
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
	va_list ap;
	char	*toprint;
	char	toprint_c;
   	int 	toprint_len;
	int		flags[5];
	int		width;
	int		precision;
	char	spec;
}				t_struct;

int			ft_printf(const char *format, ...);
void		print_width_front(t_struct *ptr_struct);
void		print_width_back(t_struct *ptr_struct);
void		convert_all(t_struct *ptr_struct);
int			ft_isflag(char c);
int			ft_isspec(char c);
int			ft_isintspec(char c);
void		parse_total(char *toparse, t_struct *ptr_struct);
void		final_print(t_struct *ptr_struct);
void		struct_init(t_struct *ptr_struct);
#endif
