/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:26:29 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 15:32:51 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char *toparse, t_struct	*ptr_struct) // toparse = ptr sur le % de la chaine ?
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

	if (ft_isdigit(*toparse))
	{
		start = toparse;
		while (ft_isdigit(*toparse))
			toparse++;
		ptr_struct->width = ft_atoi(toparse - start); //atoi sur la chaine de chiffre ?
	}
	else if (*toparse == '*')
		ptr_struct->width = va_arg(ap, int);
	return (toparse);
}

char	*parse_precision(char toparse, t_struct *ptr_struct)
{
	char *start;

	//va chercher la precision(elle est precedee d'un point) et la mettre dans la struct
	if (*toparse == '.')
	{
		toparse++;//cest un ., donc je vais derriere pour voir les chiffres
		if (ft_isdigit(*toparse))
		{
			start = toparse;
			while (ft_isdigit(*toparse))
				toparse++;
			ptr_struct->width = ft_atoi(toparse - start); //atoi sur la chaine de chiffre ?
		}
		else if (*toparse = '*')
			ptr_struct->precision = va_arg(ap, int);
	}
	return (toparse);
}

void	parse_spec(char *toparse, t_struct *ptr_struct)
{
	if (ft_isspec(*toparse))
		ptr_struct->spec = *toparse;
	else
		return (-1);
}

void	parse_total(char *toparse, t_struct *ptr_struct)
{
	if (!(ft_strchr(toparse, '%')))
		ft_putstr_fd(1, toparse);
	else
	{
		parse_flags(toparse, ptr_struct);
		parse_width(toparse, ptr_struct);
		parse_precision(toparse, ptr_struct);
		parse_spec(toparse, ptr_struct);
	}
}
