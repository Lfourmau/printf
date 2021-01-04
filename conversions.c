/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:39:06 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/04 15:56:54 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//pas de convert_c = elle se fait seule  pendant affchage comme putchar

void ft_convert_s(char *toconvert, ptr struct)//donner l'argument correspondant
{
	//strdup pour copier la chaine et la traiter
	t_struct->toprint = ft_strdup(toconvert);
}

void ft_convert_p(char *toconvert)//donner l'argument correspondant
{
	ft_itoa_base(&t_struct->toprint, "0123456789abcdef");
}

void ft_convert_di(int intsigne)//donner l'argument correspondant
{
	t_struct->toprint = ft_itoa(intsigne)
}

void ft_convert_u(char *toconvert)//donner l'argument correspondant
{
	//passer l'arg en int decimal non signe
}

void ft_convert_xX(char *toconvert)//donner l'argument correspondant
{
	if (t_struct->spec == 'x')
		t_struct->res = convert_base(t_struct->res, "0123456789abcdef");
	if (t_struct->spec == 'X')
		t_struct->res = convert_base(t_struct->res, "0123456789ABCDEF");
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
		ft_convert_xX(t_struct->argument);
} 
