# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 15:40:56 by loic              #+#    #+#              #
#    Updated: 2021/01/05 12:40:32 by lfourmau         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #
#
#
#
#
#
#

main :
	gcc main.c -D COLORS -D PRINTF=printf -D PRINTF_=printf 
	./a.out > toto.txt
	more -R toto.txt
	rm toto.txt
