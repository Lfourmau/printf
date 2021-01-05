/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:39:06 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 15:53:40 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//pas de convert_c = elle se fait seule  pendant affchage comme putchar

char	*ft_convert_s(char *toconvert)
{
	//strdup pour copier la chaine et la traiter
	return (ft_strdup(toconvert));
}

char	*ft_convert_p(void *toconvert)
{
	return (ft_itoa_base(&toconvert, "0123456789abcdef"));
}

char 	*ft_convert_di(int nb)
{
	return (ft_itoa_base(nb, "0123456789"));
}

char	*ft_convert_u(unsigned int nb)
{
	return (ft_itoa_base(nb, "0123456789"));
}

char	*ft_convert_xX(unsigned int nb)
{
	if (ptr_struct->spec == 'x')
		return (ft_itoa_base(nb, "0123456789abcdef"));
	if (ptr_struct->spec == 'X')
		return(ft_itoa_base(nb, "0123456789ABCDEF"));

}

char *convert_all(t_struct *ptr_struct)
{
	if (ptr_struct->spec == 'c')
		ptr_struct->toprint = va_arg(ptr_struct->ap, int);
	if (ptr_struct->spec == 's')
		ptr_struct->toprint = ft_convert_s(va_arg(ptr_struct->ap, char *));
	if (ptr_struct->spec == 'p')
		ptr_struct->toprint = ft_convert_p(va_arg(ptr_struct->ap, void *));
	if (ptr_struct->spec == 'd' || ptr_struct->spec == 'i')
		ptr_struct->toprint = ft_convert_di(va_arg(ptr_struct->ap, int));
	if (ptr_struct->spec == 'u')
		ptr_struct->toprint = ft_convert_u(va_arg(ptr_struct->ap, unsigned int));
	if (ptr_struct->spec == 'x' || ptr_struct->spec == 'X')
		ptr_struct->toprint = ft_convert_xX(va_arg((ptr_struct->ap, unsigned int));
	ptr_struct->toprint_len = ft_strlen(ptr_struct->toprint);
} 
