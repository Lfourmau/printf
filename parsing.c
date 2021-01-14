/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:26:29 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/14 11:12:56 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_flags(char *toparse, t_struct *ts)
{
	while (ft_isflag(*toparse))
	{
		if (*toparse == '-')
			ts->flags[0] = 1;
		if (*toparse == '0')
			ts->flags[1] = 1;
		toparse++;
	}
	return (toparse);
}

char	*parse_width(char *toparse, t_struct *ts)
{
	if (ft_isdigit(*toparse))
	{
		ts->width = ft_atoi(toparse);
		while (ft_isdigit(*toparse))
			toparse++;
	}
	else if (*toparse == '*')
	{
		ts->width = va_arg(ts->ap, int);
		toparse++;
	}
	if (ts->width < 0)
	{
		ts->flags[0] = 1;
		ts->width *= -1;
	}
	return (toparse);
}

char	*parse_precision(char *toparse, t_struct *ts)
{
	if (*toparse == '.')
	{
		ts->flags[2] = 1;
		toparse++;
		if (ft_isdigit(*toparse))
		{
			ts->precision = ft_atoi(toparse);
			while (ft_isdigit(*toparse))
				toparse++;
		}
		else if (*toparse == '*')
		{
			ts->precision = va_arg(ts->ap, int);
			toparse++;
		}
		if (ts->precision < 0)
		{
			ts->flags[2] = 0;
			ts->precision = 0;
		}
	}
	return (toparse);
}

char	*parse_spec(char *toparse, t_struct *ts)
{
	if (ts->flags[0] == 1 && ts->flags[1] == 1)
		ts->flags[1] = 0;
	if (ft_isspec(*toparse))
		ts->spec = *toparse;
	toparse++;
	return (toparse);
}

char	*parse_total(char *toparse, t_struct *ts)
{
	char *parse_next;

	toparse++;
	if (*toparse)
	{
		parse_next = parse_flags(toparse, ts);
		parse_next = parse_width(parse_next, ts);
		parse_next = parse_precision(parse_next, ts);
		toparse = parse_spec(parse_next, ts);
	}
	return (toparse);
}
