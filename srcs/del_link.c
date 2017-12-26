/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:40:36 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/20 17:33:47 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	del_link(t_filelist **head)
{
	t_filelist *tmp;

	if (!head || !*head)
		return ;
	if ((*head)->next == *head)
		tmp = NULL;
	else
	{
		tmp = (*head)->next;
		(*head)->prev->next = tmp;
		tmp->prev = (*head)->prev;
	}
	free((*head)->path);
	free(*head);
	*head = tmp;
}
