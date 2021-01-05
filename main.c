/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:35:15 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/05 12:39:35 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
//#include "ft_printf.h"
int main(void)
{
	char	*type[11]={"","c","s","p","d","i","u","x","X","%","o"};
	char	*flag[6]={"","-","#"," ","+", "0"};
	char	*width[4]={"", "3", "18", "15"};
	char	*prec[4] ={"",".0",".2",".20"};
	char	s2[20];
	size_t	i,j,j1,k,l,m;
	int		res;
	char	*blabla = "AbCdEfGhiJ";
	int		d_int = 'y';
	void	*ptr = (void *)42;
//	for (i=0;i<(sizeof(type)/sizeof(*type));i++) {
	i = 5;
		for (j=0;j<(sizeof(flag)/sizeof(*flag));j++) {
			for (j1=0;j1<(sizeof(flag)/sizeof(*flag));j1++) {
				if (j && j == j1)
					break;
				for (l=0;l<(sizeof(width)/sizeof(*width));l++) {
					for (m=0;m<(sizeof(prec)/sizeof(*prec));m++) {
						s2[0]='%';
						for (k=1;k<sizeof(s2);k++)
							s2[k]=0;
						strcat(s2,flag[j]);
						strcat(s2,flag[j1]);
						strcat(s2,width[l]);
						strcat(s2,prec[m]);
						strcat(s2,type[i]);
#ifdef COLORS
						PRINTF_("\033[1;49;93m");
#endif
						PRINTF_("{");
#ifdef COLORS
						PRINTF_("\033[1;49;32m");
#endif
						PRINTF_("%10s",s2);
#ifdef COLORS
						PRINTF_("\033[0m");
#endif
						PRINTF_(" >>");
						if (type[i][0] == '%' || type[i][0] == 'c')
							res=PRINTF(s2, d_int);
						if (type[i][0] == 's')
							res=PRINTF(s2, blabla);
						if (type[i][0] == 'p')
							res=PRINTF(s2, ptr);
						if (strchr("diuxXo", type[i][0]))
							res=PRINTF(s2, 
									-(i+1)*(j+1)*(j1+1)*(k+1)*(l+1)*(m+1));
						PRINTF_("<< ");
#ifdef COLORS
						PRINTF_("\033[1;49;37m");
#endif
						PRINTF_("%d",res);
#ifdef COLORS
						PRINTF_("\033[1;49;93m");
#endif
						PRINTF_("}");
#ifdef COLORS
						PRINTF_("\033[0m");
#endif
						PRINTF_("\n");
					}
				}
			}
		}
		PRINTF("\n\n");
//	}
}
