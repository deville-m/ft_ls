/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:49:28 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/18 19:46:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_elem(t_filelist **head, t_filelist *elem)
{
	if (!head || !elem)
		return ;
	if (!*head)
	{
		elem->next = elem;
		elem->prev = elem;
	}
	else
	{
		elem->next = *head;
		elem->prev = (*head)->prev;
		(*head)->prev->next = elem;
		(*head)->prev = elem;
	}
	*head = elem;
}
