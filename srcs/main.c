/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:11:58 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 17:41:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_option	option;
	t_filelist	*list;
	int			optind;

	if (!(optind = parse_option(argc, argv, &option)))
		return (1);
	if (!(list = parse_arg(optind, argc, argv, option)))
		return (2);
	if (argc - optind > 1)
		multiple_arg(list, option);
	else
		one_arg(list, option);
	return (0);
}
