/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:39:06 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/04 17:03:53 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//pas de convert_c = elle se fait seule  pendant affchage comme putchar

void ft_convert_s(char *toconvert, ptr struct)//donner l'argument correspondant
{
	//strdup pour copier la chaine et la traiter
	t_struct->toprint = ft_strdup(toconvert);
}

void ft_convert_p(void *toconvert)//donner l'argument correspondant
{
	ft_itoa_base(&t_struct->toprint, "0123456789abcdef");
}

void ft_convert_di(int)//donner l'argument correspondant
{
	t_struct->toprint = ft_itoa(int)
}

void ft_convert_u(unsigned int)//donner l'argument correspondant
{
	//passer l'arg en int decimal non signe
}

void ft_convert_xX(unsigned int)//donner l'argument correspondant
{
	if (t_struct->spec == 'x')
		t_struct->toprint = itoa(unsigned int, "0123456789abcdef");
	if (t_struct->spec == 'X')
		t_struct->toprint = itoa_base(unsigned int, "0123456789ABCDEF");
}

char *convert_all(argument, t_struct *ptr)
{
	if (t_struct->spec == 'c')
		//t_struct->toprint = l'argument ?
		t_struct->toprint = ft_convert_c(argument);
	if (t_struct->spec == 's')
		//t_struct->toprint = l'argument ? en char * pour la conversion
		t_struct->toprint = ft_convert_s(argument);
	if (t_struct->spec == 'p')
		t_struct->toprint = ft_convert_p(argument);
	if (t_struct->spec == 'd' || t_struct->spec == 'i')
		//t_struct->res = l'argument ? stocker en unsigned dans la struct pour l'utiliser lrs de la conversion
		t_struct->toprint = ft_convert_di(argument);
	if (t_struct->spec == 'u')
		//t_struct->res = l'argument ? stocker en unsigned dans la struct pour l'utiliser lrs de la conversion
		t_struct->toprint = ft_convert_u(argument);
	if (t_struct->spec == 'x' || t_struct->spec == 'X')
		//t_struct->res = l'argument ? stocker en unsigned dans la struct pour l'utiliser lrs de la conversion
		ft_convert_xX(t_struct->argument);
} 
