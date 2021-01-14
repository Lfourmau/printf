/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:10:08 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 11:24:16 by lfourmau         ###   ########lyon.fr   */
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
	int			flags[3];
	int			width;
	int			precision;
	int			len_or_prec;
	int			min;
	int			max;
	int			nbspaces;
	int			nbzero;
	int			return_val;
	char		spec;
	int			neg;
}				t_struct;

int			ft_printf(const char *format, ...);
void		convert_all(t_struct *ts);
int			ft_isflag(char c);
int			ft_isspec(char c);
int			ft_isintspec(char c);
char		*parse_total(char *toparse, t_struct *ts);
void		struct_init(t_struct *ts);
int			ft_min(int nb1, int nb2);
int			ft_max(int nb1, int nb2);
char		*ft_itoa_base(long long int nb, char *base);
char		*ft_itoa_base_p(unsigned long long nb, char *base);
void		ft_lencmp(t_struct *ts);
void		ft_displ_int(t_struct *ts);
void		ft_displ_str(t_struct *ts);
void		ft_displ_char(t_struct *ts);
char		*ft_convert_s(char *toconvert, t_struct *ts);
char		*ft_convert_p(void *toconvert, t_struct *ts);
char		*ft_convert_di(long long int nb, t_struct *ts);
char		*ft_convert_u(unsigned int nb, t_struct *ts);
char		*ft_convert_x(unsigned int nb, t_struct *ts);
void		ft_displ_spc(t_struct *ts, int i);
void		ft_displ_zero(t_struct *ts, int i);
void		ft_displ_pre(t_struct *ts);
#endif
