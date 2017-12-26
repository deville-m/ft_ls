/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:01:09 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/20 11:22:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filelist		*pop_elem(t_filelist **head)
{
	t_filelist *res;

	if (!head || !*head)
		return (NULL);
	res = *head;
	if ((*head)->next == *head)
	{
		*head = NULL;
		return (res);
	}
	(*head)->prev->next = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	*head = (*head)->next;
	return (res);
}
