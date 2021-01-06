/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:26:29 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/06 15:55:06 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_flags(char *toparse, t_struct	*ptr_struct) // toparse = ptr sur le % de la chaine ?
{
	while (ft_isflag(*toparse))
	{
		if (*toparse == '-')
			ptr_struct->flags[0] = 1;
		if (*toparse == '0')
			ptr_struct->flags[1] = 1;
		if (*toparse == ' ')
			ptr_struct->flags[2] = 1;
		if (*toparse == '#')
			ptr_struct->flags[3] = 1;
		if (*toparse == '+')
			ptr_struct->flags[4] = 1;
		toparse++;
	}
	return (toparse); //pour reprendre de la ou on s'est arrete a la fct suivante
}

char	*parse_width(char *toparse, t_struct *ptr_struct) //toparse == resultat de la fct du dessus
{
	char *start;
	long nb_atoi;

	if (ft_isdigit(*toparse))
	{
		start = toparse;
		while (ft_isdigit(*toparse))
			toparse++;
		nb_atoi = toparse - start;
		ptr_struct->width = ft_atoi(start + nb_atoi); //atoi sur la chaine de chiffre ?
	}
	else if (*toparse == '*')
	{
		ptr_struct->width = va_arg(ptr_struct->ap, int);
		if (ptr_struct->width < 0)
			ptr_struct->width = 0;
	}
	return (toparse);
}

char	*parse_precision(char *toparse, t_struct *ptr_struct)
{
	char *start;
	long nb_atoi;

	if (*toparse == '.')
	{
		toparse++;//cest un ., donc je vais derriere pour voir les chiffres
		if (ft_isdigit(*toparse))
		{
			start = toparse;
			while (ft_isdigit(*toparse))
				toparse++;
			nb_atoi = toparse - start;
			ptr_struct->width = ft_atoi(start + nb_atoi); //atoi sur la chaine de chiffre ?
		}
		else if (*toparse == '*')
		{
			ptr_struct->precision = va_arg(ptr_struct->ap, int);
			if (ptr_struct->precision < 0)
				ptr_struct->precision = 0;
		}
	}
	return (toparse);
}

void	parse_spec(char *toparse, t_struct *ptr_struct)
{
	if (ft_isspec(*toparse))
		ptr_struct->spec = *toparse;
}

void	parse_total(char *toparse, t_struct *ptr_struct)
{
	while (*toparse &&*toparse != '%')
	{
		ft_putchar_fd(*toparse, 1);
		toparse++;
	}
	if (*toparse)
	{
		parse_flags(toparse, ptr_struct);
		parse_width(toparse, ptr_struct);
		parse_precision(toparse, ptr_struct);
		parse_spec(toparse, ptr_struct);
	}
}
