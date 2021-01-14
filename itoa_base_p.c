/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:15:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 11:17:26 by lfourmau         ###   ########lyon.fr   */
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

static void	ft_recursive(unsigned long long nb, char *str, char *base, int indx)
{
	if (nb >= ft_strlen(base))
		ft_recursive(nb / ft_strlen(base), str, base, indx - 1);
	str[indx] = base[nb % ft_strlen(base)];
}

char	*ft_itoa_base_p(unsigned long long nb, char *base)
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
