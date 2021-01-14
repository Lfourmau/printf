/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:00:49 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 11:03:02 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_s(char *toconvert, t_struct *ts)
{
	if (!toconvert)
		return (ft_strdup("(null)"));
	return (ft_strdup(toconvert));
}

char	*ft_convert_p(void *toconvert, t_struct *ts)
{
	return (ft_itoa_base_p((unsigned long long)toconvert, "0123456789abcdef"));
}

char	*ft_convert_di(long long int nb, t_struct *ts)
{
	if (nb < 0)
		ts->neg = 1;
	return (ft_itoa_base(nb, "0123456789"));
}

char	*ft_convert_u(unsigned int nb, t_struct *ts)
{
	return (ft_itoa_base(nb, "0123456789"));
}

char	*ft_convert_xX(unsigned int nb, t_struct *ts)
{
	if (ts->spec == 'x')
		return (ft_itoa_base(nb, "0123456789abcdef"));
	else
		return (ft_itoa_base(nb, "0123456789ABCDEF"));
}
