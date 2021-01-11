/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:39:06 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/11 14:09:26 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//pas de convert_c = elle se fait seule  pendant affchage comme putchar

char	*ft_convert_s(char *toconvert, t_struct *ptr_struct)
{
	return (ft_strdup(toconvert)); //ok
}

char	*ft_convert_p(void *toconvert, t_struct *ptr_struct)
{
	return (ft_itoa_base((unsigned long long)toconvert, "0123456789abcdef"));
}

char 	*ft_convert_di(int nb, t_struct *ptr_struct)
{
	return (ft_itoa_base(nb, "0123456789")); //ok
}

char	*ft_convert_u(unsigned int nb, t_struct *ptr_struct)
{
	char *tmp;

	tmp = ft_itoa_base(nb, "0123456789");
	return (tmp);
}

char	*ft_convert_xX(unsigned int nb, t_struct *ptr_struct)
{
	if (ptr_struct->spec == 'x')
		return (ft_itoa_base(nb, "0123456789abcdef")); //ok
	else
		return(ft_itoa_base(nb, "0123456789ABCDEF")); //ok

}

void	convert_all(t_struct *ptr_struct)
{
	size_t len;

	if (ptr_struct->spec == 'c')
		ptr_struct->toprint_c = va_arg(ptr_struct->ap, int);
	if (ptr_struct->spec == 's')
		ptr_struct->toprint = ft_convert_s(va_arg(ptr_struct->ap, char *), ptr_struct);
	if (ptr_struct->spec == 'p')
		ptr_struct->toprint = ft_convert_p(va_arg(ptr_struct->ap, void *), ptr_struct);
	if (ptr_struct->spec == 'd' || ptr_struct->spec == 'i')
		ptr_struct->toprint = ft_convert_di(va_arg(ptr_struct->ap, int), ptr_struct);
	if (ptr_struct->spec == 'u')
		ptr_struct->toprint = ft_convert_u(va_arg(ptr_struct->ap, unsigned int), ptr_struct);
	if (ptr_struct->spec == 'x' || ptr_struct->spec == 'X')
		ptr_struct->toprint = ft_convert_xX(va_arg(ptr_struct->ap, unsigned int), ptr_struct);
	if (ptr_struct->toprint)
		ptr_struct->toprint_len = strlen(ptr_struct->toprint);
	ptr_struct->initial_len = ptr_struct->toprint_len;
	if (ptr_struct->precision > ptr_struct->toprint_len)
		ptr_struct->toprint_len += ptr_struct->precision - ptr_struct->toprint_len;
}
