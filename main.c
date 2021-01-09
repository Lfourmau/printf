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
	
	printf("\\\\\\\033[92mTEST d -14.6 et s 20.4\033[0m///\n");
	ft_printf("\033[33mca fait %-14.6d ans que je %20.4s travaille sur printf\n\033[0m", 25, "BRISE DES MERES");
	printf("ca fait %-14.6d ans que je %20.4s travaille sur printf\n", 25, "BRISE DES MERES");

	printf("\\\\\\\033[92mTEST d 14.6\033[0m///\n");
	ft_printf("\033[33mca fait %14.6d ans que je  travaille sur printf\n\033[0m", 25);
	printf("ca fait %14.6d ans que je  travaille sur printf\n", 25);

	printf("\\\\\\\033[92mTEST s 14.6\033[0m///\n");
	ft_printf("\033[33mca fait %14.6s ans que je  travaille sur printf\n\033[0m", "blehnlouh");
	printf("ca fait %14.6s ans que je  travaille sur printf\n", "blehblouh");

	printf("\\\\\\\033[92mTEST u avec flag 014.6\033[0m///\n");
	ft_printf("\033[33mca fait %014.6u ans que je  travaille sur printf\n\033[0m", 14);
	printf("ca fait %014.6u ans que je  travaille sur printf\n", 14);

	printf("\\\\\\\033[92mTEST c sans width\033[0m///\n");
	ft_printf("\033[33mca fait %c ans que je  travaille sur printf\n\033[0m", 65);
	printf("ca fait %c ans que je  travaille sur printf\n", 65);

	printf("\\\\\\\033[92mTEST c avec width et flag -\033[0m///\n");
	ft_printf("\033[33mca fait %-15c ans que je  travaille sur printf\n\033[0m", 65);
	printf("ca fait %-15c ans que je  travaille sur printf\n", 65);

	printf("\\\\\\\033[92mTEST c avec width\033[0m///\n");
	ft_printf("\033[33mca fait %15c ans que je  travaille sur printf\n\033[0m", 65);
	printf("ca fait %15c ans que je  travaille sur printf\n", 65);

	printf("\\\\\\\033[92mTEST x avec 012.3\033[0m///\n");
	ft_printf("\033[33mca fait %012.3x ans que je  travaille sur printf\n\033[0m", 65);
	printf("ca fait %012.3x ans que je  travaille sur printf\n", 65);

	printf("\\\\\\\033[92mTEST X avec 012.3\033[0m///\n");
	ft_printf("\033[33mca fait %012.3X ans que je  travaille sur printf\n\033[0m", 65);
	printf("ca fait %012.3X ans que je  travaille sur printf\n", 65);
}
