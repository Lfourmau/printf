/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:26:29 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/27 14:14:14 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(char *toparse, pointeur sur ma struct) // toparse = ptr sur le % de la chaine ?
{
	while (ft_isflag(*toparse))
	{
		//un if pour chaque flag qui le met dans le bon index du tableau de la struct
		if (*toparse == '-')
			t_struct->flags[0] = '-'; //met le flag a son index dans la struct
		if (*toparse == '0')
			t_struct->flags[1] = '0'; // met le flag a son index dans la strcut
		toparse++;
	}

	//va chercher les flags et les mettre dans la struct
}

int		parse_width(char *1er argument du printf, struct a modifier)
{
	//va chercher la width si il y a des chiffres et va le rercup dans les arg si asterisque
	//peut etre faire un atoi
	//doit retourner un int pout stocker la width dans la struct
}

int		parse_precision(char *1er argument du printf, struct a modifier)
{
	//va chercher la precision(elle est precedee d'un point) et la mettre dans la struct
	//doit retourner un int pout stocker la prec dans la struct
}
