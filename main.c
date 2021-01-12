/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:27:05 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/12 18:35:19 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	int testP = 5;
	printf("\\\\\\\033[92mTEST\033[0m///\n");
	printf("return : [%d]\n",ft_printf(" %10p %10p ", 1, -1));
	printf("return : [%d]\n",printf(" %10p %10p ", 1, -1));

	
	printf("[%s]\n",ft_itoa_base(-45, "0123456789"));
	printf("\\\\\\\033[92mTEST\033[0m///\n");
	printf("return : [%d]\n",ft_printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011));
	printf("return : [%d]\n",printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011));

	 printf("\\\\\\\033[92mTEST d -14.6 et s 20.4\033[0m///\n");
	 printf("return : [%d]\n", ft_printf("ca fait |%-14.6d| ans que je %20.4s travaille sur printf\n", 25, "BRISE DES MERES"));
	 printf("return : [%d]\n", printf("ca fait |%-14.6d| ans que je %20.4s travaille sur printf\n", 25, "BRISE DES MERES"));

	 printf("\\\\\\\033[92mTEST d -14.6 et s 20.4\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%-14.6d| ans que je %20.4s travaille sur printf\n", 25, "BRISE DES MERES"));
	 printf("return : [%d]\n",printf("ca fait |%-14.6d| ans que je %20.4s travaille sur printf\n", 25, "BRISE DES MERES"));

	 printf("\\\\\\\033[92mTEST d 14.6\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%14.6d| ans que je  travaille sur printf\n", 25));
	 printf("return : [%d]\n",printf("ca fait |%14.6d| ans que je  travaille sur printf\n", 25));

	 printf("\\\\\\\033[92mTEST s 14.6\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%14.6s| ans que je  travaille sur printf\n", "blehnlouh"));
	 printf("return : [%d]\n",printf("ca fait |%14.6s| ans que je  travaille sur printf\n", "blehblouh"));

	 printf("\\\\\\\033[92mTEST u avec flag 014.6\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%014.6u| ans que je  travaille sur printf\n", 14));
	 printf("return : [%d]\n",printf("ca fait |%014.6u| ans que je  travaille sur printf\n", 14));

	 printf("\\\\\\\033[92mTEST c sans width\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%c| ans que je travaille sur printf\n", 65));
	 printf("return : [%d]\n",printf("ca fait |%c| ans que je travaille sur printf\n", 65));

	 printf("\\\\\\\033[92mTEST c avec width et flag -\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%-15c| ans que je travaille sur printf\n", 65));
	 printf("return : [%d]\n",printf("ca fait |%-15c| ans que je travaille sur printf\n", 65));

	 printf("\\\\\\\033[92mTEST c avec width\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%15c| ans que je  travaille sur printf\n", 65));
	 printf("return : [%d]\n",printf("ca fait |%15c| ans que je  travaille sur printf\n", 65));

	 printf("\\\\\\\033[92mTEST x avec 012.3\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%012.3x| ans que je  travaille sur printf\n", 255));
	 printf("return : [%d]\n",printf("ca fait |%012.3x| ans que je  travaille sur printf\n", 255));

	 printf("\\\\\\\033[92mTEST X avec 012.3\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%012.3X| ans que je  travaille sur printf\n", 255));
	 printf("return : [%d]\n",printf("ca fait |%012.3X| ans que je  travaille sur printf\n", 255));

	 printf("\\\\\\\033[92mTEST p\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%p| ans que je  travaille sur printf\n", &testP));
	 printf("return : [%d]\n",printf("ca fait |%p| ans que je  travaille sur printf\n", &testP));

	printf("\\\\\\\033[92mTEST p avec flag -25\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%-25p| ans que je  travaille sur printf\n", &testP));
	printf("return : [%d]\n",printf("ca fait |%-25p| ans que je  travaille sur printf\n", &testP));

	 printf("\\\\\\\033[92mTEST p avec 2\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%2p| ans que je  travaille sur printf\n", &testP));
	 printf("return : [%d]\n",printf("ca fait |%2p| ans que je  travaille sur printf\n", &testP));

	 printf("\\\\\\\033[92mTEST avec d et 2\033[0m///\n");
	 printf("return : [%d]\n",ft_printf("ca fait |%2d| ans que je  travaille sur printf\n", 6589));
	 printf("return : [%d]\n",printf("ca fait |%2d| ans que je  travaille sur printf\n", 6589));

	return (0);
}	
