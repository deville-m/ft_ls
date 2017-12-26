/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:37:11 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/18 19:44:32 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_back(t_filelist **head, t_filelist *elem)
{
	if (!head || !elem)
		return ;
	add_elem(head, elem);
	rotate(head);
}
