/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:39:06 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/04 11:17:19 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//pas de convert_c = elle se fait seule  pendant affchage comme putchar

void ft_convert_s(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en string
}

void ft_convert_p(char *toconvert)//donner l'argument correspondant
{
	//doit donner l'adresse en hexa
}

void ft_convert_di(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en int decimal signe
}

void ft_convert_u(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en int decimal non signe
}

void ft_convert_xX(char *toconvert)//donner l'argument correspondant
{
	//convert base ici puis print ou direct putnbr_base dans print.c ?
}

char *convert_all(argument, t_struct *ptr)
{
	if (t_struct->spec == 'c')
		t_struct->toprint = ft_convert_c(argument);
	if (t_struct->spec == 's')
		t_struct->toprint = ft_convert_s(argument);
	if (t_struct->spec == 'p')
		t_struct->toprint = ft_convert_p(argument);
	if (t_struct->spec == 'd' || t_struct->spec == 'i')
		t_struct->toprint = ft_convert_di(argument);
	if (t_struct->spec == 'u')
		t_struct->toprint = ft_convert_u(argument);
	if (t_struct->spec == 'x' || t_struct->spec == 'X')
		t_struct->toprint = ft_convert_xX(argument); //les deux sont en hexa, il faut juste strtoUpper
} 
