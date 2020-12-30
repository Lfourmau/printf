/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:26:29 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/29 11:25:36 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char *toparse, t_struct	*ptr) // toparse = ptr sur le % de la chaine ?
{
	while (ft_isflag(*toparse))
	{
		if (*toparse == '-')
			t_struct->flags[0] = '-';
		if (*toparse == '0')
			t_struct->flags[1] = '0';
		if (*toparse == ' ')
			t_struct->flags[2] = ' ';
		if (*toparse == '#')
			t_struct->flags[3] = '#';
		if (*toparse == '+')
			t_struct->flags[4] = '+';
		toparse++;
	}
	return (toparse); //pour reprendre de la ou on s'est arrete a la fct suivante
}

char	*parse_width(char *toparse, t_struct *ptr) //toparse == resultat de la fct du dessus
{
	char *start;

	if (ft_isdigit(*toparse))
	{
		start = toparse;
		while (ft_isdigit(*toparse))
			toparse++;
		t_struct->width = ft_atoi(toparse - start); //atoi sur la chaine de chiffre ?
	}
	else if (*toparse == '*')
	{
		//aller chercher le prochain argument
	}
	return (toparse);
}

char	*parse_precision(char *1er argument du printf, t_struct *ptr)
{
	char *start;

	//va chercher la precision(elle est precedee d'un point) et la mettre dans la struct
	if (*toparse == '.')
	{
		toparse++;//cest un ., donc je vais derriere pour voir les chiffres
		start = toparse;
		while (ft_isdigit(*toparse))
			toparse++;
		t_struct->width = ft_atoi(toparse - start); //atoi sur la chaine de chiffre ?
		//inserer qq part la condition pour l'asterisque
	}
	return (toparse);
}

void	parse_spec(char *toparse, t_struct *ptr)
{
	if (ft_isspec(*toparse))
		t_struct->spec = *toparse;
	else
		return (-1);
}

void	parse_total(char *toparse, t_struct *ptr)
{
	if (!(ft_strchr(toparse, '%')))
		ft_putstr_fd(1, toparse);
	else
	{
		parse_flags(toparse, structure);
		parse_width(toparse, structure);
		parse_precision(toparse, structure);
		parse_spec(toparse, structure);
	}
}
