/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:15:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 11:28:42 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count(unsigned long long nb, char *base)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= ft_strlen(base))
	{
		nb /= ft_strlen(base);
		i++;
	}
	i++;
	return (i);
}

static void		ft_recursive(unsigned long long nb, char *s, char *bs, int indx)
{
	if (nb >= ft_strlen(bs))
		ft_recursive(nb / ft_strlen(bs), s, bs, indx - 1);
	s[indx] = bs[nb % ft_strlen(bs)];
}

char			*ft_itoa_base_p(unsigned long long nb, char *base)
{
	char	*str;
	int		index;

	index = ft_count(nb, base);
	str = malloc(sizeof(char) * (index + 1));
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[index] = 0;
	ft_recursive(nb, str, base, index - 1);
	return (str);
}
