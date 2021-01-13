/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:27:05 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/13 17:16:12 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	o________________________________o(char *test)
{
	printf("\n--- \033[92mTEST %s\033[0m ---\n", test);
}

void	print_res(int result)
{
	printf("\033[31m -> %d\033[0m\n", result - 2);
}

int		main(void)
{
	int pointer;

	pointer = 5;
	o________________________________o("");
	print_res(ft_printf("|%1s| |%1s|", "123", "4567"));
	print_res(printf("|%1s| |%1s|", "123", "4567"));
	o________________________________o("");
	print_res(ft_printf("|%-4s| |%4s|", "123", "4567"));
	print_res(printf("|%-4s| |%4s|", "123", "4567"));
	o________________________________o("d -14.6 et s 20.4");
	print_res(ft_printf("|%*s| |%s|", 10, "123", "4567"));
	print_res(printf("|%*s| |%s|", 10, "123", "4567"));
	// o________________________________o("d -14.6 et s 20.4");
	// print_res(ft_printf("|%-3d|", 0));
	// print_res(printf("|%-3d|", 0));
	// o________________________________o("");
	// print_res(ft_printf("|%2d|", 33));
	// print_res(printf("|%2d|", 33));
	// o________________________________o("");
	// print_res(ft_printf("|%3d|", -14));
	// print_res(printf("|%3d|", -14));
	// o________________________________o("d -14.6 et s 20.4");
	// print_res(ft_printf("|%d|", 0));
	// print_res(printf("|%d|", 0));
	// o________________________________o("d -14.6 et s 20.4");
	// print_res(ft_printf("|%-d|", 0));
	// print_res(printf("|%-d|", 0));
	// o________________________________o("d 14.6");
	// print_res(ft_printf("|%14.6d|", 25));
	// print_res(printf("|%14.6d|", 25));
	// o________________________________o("s 14.6");
	// print_res(ft_printf("|%14.6s|", "blehnlouh"));
	// print_res(printf("|%14.6s|", "blehblouh"));
	// o________________________________o("u avec flag 014.6");
	// print_res(ft_printf("|%014.6u|", 14));
	// print_res(printf("|%014.6u|", 14));
	// o________________________________o("c sans width");
	// print_res(ft_printf("|%c|", 65));
	// print_res(printf("|%c|", 65));
	// o________________________________o("c avec width et flag -");
	// print_res(ft_printf("|%-15c|", 65));
	// print_res(printf("|%-15c|", 65));
	// o________________________________o("c avec width");
	// print_res(ft_printf("|%15c|", 65));
	// print_res(printf("|%15c|", 65));
	// o________________________________o("x avec 012.3");
	// print_res(ft_printf("|%012.3x|", 255));
	// print_res(printf("|%012.3x|", 255));
	// o________________________________o("X avec 012.3");
	// print_res(ft_printf("|%012.3X|", 255));
	// print_res(printf("|%012.3X|", 255));
	// o________________________________o("p");
	// print_res(ft_printf("|%p|", &pointer));
	// print_res(printf("|%p|", &pointer));
	// o________________________________o("p avec flag -25");
	// print_res(ft_printf("|%-25p|", &pointer));
	// print_res(printf("|%-25p|", &pointer));
	// o________________________________o("p avec 2");
	// print_res(ft_printf("|%2p|", &pointer));
	// print_res(printf("|%2p|", &pointer));
	// o________________________________o("avec d et 2");
	// print_res(ft_printf("|%2d|", 6589));
	// print_res(printf("|%2d|", 6589));
	return (0);
}