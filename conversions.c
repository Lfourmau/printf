/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:39:06 by lfourmau          #+#    #+#             */
/*   Updated: 2020/12/29 14:43:42 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void ft_convert_c(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en char
}

void ft_convert_s(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en string
}

void ft_convert_p(char *toconvert)//donner l'argument correspondant
{
	//doit donner l'adresse en hexa
}

void ft_convert_d(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en int
}

void ft_convert_i(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en int decimal signe
}

void ft_convert_u(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en int decimal non signe
}

void ft_convert_x(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en int hexa non signe avec abcdef
}

void ft_convert_X(char *toconvert)//donner l'argument correspondant
{
	//pareil que petit x mais avec ABCDEF
}

char *convert_all(argument, t_struct *ptr)
{
	if (t_struct->spec == 'c')
		t_struct->toprint = ft_convert_c(argument);
	if (t_struct->spec == 's')
		t_struct->toprint = ft_convert_s(argument);
	if (t_struct->spec == 'p')
		t_struct->toprint = ft_convert_p(argument);
	if (t_struct->spec == 'd')
		t_struct->toprint = ft_convert_d(argument);
	if (t_struct->spec == 'i')
		t_struct->toprint = ft_convert_i(argument);
	if (t_struct->spec == 'u')
		t_struct->toprint = ft_convert_u(argument);
	if (t_struct->spec == 'x')
		t_struct->toprint = ft_convert_x(argument);
	if (t_struct->spec == 'X')
		t_struct->toprint = ft_convert_X(argument);
} 
