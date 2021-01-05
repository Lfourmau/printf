/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:10:08 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 13:26:25 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_struct
{
	va_list *ap;
	char	*toprint; 
	int		flags[5];
	int		width;
	int		precision;
	char	spec;
}				t_struct;


 int		ft_isspec(char c);
 int		ft_isflag(char c);
void 		parse_total(char *toparse, t_struct *ptr);
char		*convert_all(argument, t_struct *ptr);
void		final_print();
void		app_flags(structure, t_struct *ptr);


#endif
