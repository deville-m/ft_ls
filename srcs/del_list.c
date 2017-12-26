/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:13:34 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/18 19:51:53 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_list(t_filelist **head)
{
	t_filelist *tmp;

	if (!head || !*head)
		return ;
	(*head)->prev->next = NULL;
	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->path);
		free(*head);
		*head = tmp;
	}
}
