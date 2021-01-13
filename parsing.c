/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:26:29 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/13 14:33:25 by lfourmau         ###   ########lyon.fr   */
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
		toparse++;
	}
	return (toparse); //pour reprendre de la ou on s'est arrete a la fct suivante
}

char	*parse_width(char *toparse, t_struct *ptr_struct) //toparse == resultat de la fct du dessus
{
	if (ft_isdigit(*toparse))
	{
		ptr_struct->width = ft_atoi(toparse);
		while (ft_isdigit(*toparse))
			toparse++;
	}
	else if (*toparse == '*')
	{
		ptr_struct->width = va_arg(ptr_struct->ap, int);
		toparse++;
	}
	if (ptr_struct->width < 0)
	{
		ptr_struct->flags[0] = 1;
		ptr_struct->width *= -1;
	}
	return (toparse);
}

char	*parse_precision(char *toparse, t_struct *ptr_struct)
{
	if (*toparse == '.')
	{
		ptr_struct->flags[2] = 1;
		toparse++;//cest un ., donc je vais derriere pour voir les chiffres
		if (ft_isdigit(*toparse))
		{
			ptr_struct->precision = ft_atoi(toparse);
			while (ft_isdigit(*toparse))
				toparse++;
		}
		else if (*toparse == '*')
		{
			ptr_struct->precision = va_arg(ptr_struct->ap, int);
			toparse++;
		}
		if (ptr_struct->precision < 0)
		{
			ptr_struct->flags[2] = 0;
			ptr_struct->precision = 0;
		}
	}
	return (toparse);
}

char	*parse_spec(char *toparse, t_struct *ptr_struct)
{
	if (ptr_struct->flags[0] == 1 && ptr_struct->flags[1] == 1)
		ptr_struct->flags[1] = 0;
	if (ft_isspec(*toparse))
		ptr_struct->spec = *toparse;
	toparse++;
	return (toparse);
}

char	*parse_total(char *toparse, t_struct *ptr_struct)
{
	char *parse_next;
	toparse++;
	if (*toparse)
	{
		parse_next = parse_flags(toparse, ptr_struct);
		parse_next = parse_width(parse_next, ptr_struct);
		parse_next = parse_precision(parse_next, ptr_struct);
		toparse = parse_spec(parse_next, ptr_struct);
	}
	return (toparse);
}
