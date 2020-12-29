/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:10:08 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/29 11:25:38 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_struct
{
	char *toprint; //la chaine resultat, pour la balader d'une fct a l'autre ?
	char flags[5]; //tableau avec 1index pour chaque flag (5 car c'est le nb max de flags)
	int width; //recuperer a la sortie de parse width ?
	int precision; //recup sortie de parse precision ?
	char spec; //recup le spec pour utiliser dans des conditions ?
	int nbcaracs; //connaitre le nb de carac imprimes pour gerer le nombre de 0 ect
}				t_struct


#endif
