/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:04:10 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/13 10:04:47 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isflag(char c)
{
	return  (c == '0' || c == '-');
}

int	ft_isspec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int ft_isintspec(char c)
{
	return (c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'd');
}
