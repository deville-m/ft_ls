/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:29:17 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 20:58:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_ls.h"
#include "ft_printf.h"

static int	set_option(t_option *option, int c)
{
	if (c == 'l')
		option->l = 1;
	else if (c == 'R')
		option->rec = 1;
	else if (c == 'a')
		option->a = 1;
	else if (c == 'r')
		option->r = 1;
	else if (c == 't')
		option->t = 1;
	else if (c == '1')
		option->one_line = 1;
	else if (c == 'i')
		option->i = 1;
	else if (c == 'm')
		option->m = 1;
	else if (c == 'u')
		option->u = 1;
	else if (c == 'n')
		option->n = 1;
	else if (c == 'f')
		option->f = 1;
	else
		return (0);
	return (1);
}

int			parse_option(int argc, char **argv, t_option *option)
{
	int		c;

	ft_bzero(option, sizeof(t_option));
	while ((c = ft_getopt(argc, argv, "1aifmnlrtuR")) != -1)
	{
		if (!set_option(option, c))
		{
			ft_fprintf(2, "usage: ls [-1aifmnlrtuR] [file ...]\n");
			return (0);
		}
		if (option->f)
			option->a = 1;
		if (option->n)
			option->l = 1;
	}
	return (g_optind);
}
