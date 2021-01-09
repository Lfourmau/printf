/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:27:05 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/08 18:07:12 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	
	ft_printf("ca fait %-14.6d ans que je %s travaille sur printf\n", 25, "BRISE DES MERES");
	printf("ca fait %-14.6d ans que je %s travaille sur printf\n", 25, "BRISE DES MERES");
}
