/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:15:22 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 19:20:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ls_err(char *file)
{
	if (!file)
		return ;
	write(2, "ls: ", 4);
	perror(file);
}
