/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:27:31 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/20 16:42:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

void	print_list(const int fd, t_filelist *head)
{
	t_filelist *curr;

	if (!head)
		return ((void)ft_fprintf(fd, "(null)\n"));
	curr = head;
	ft_fprintf(fd, "%s", curr->path);
	while (curr->next != head)
	{
		curr = curr->next;
		write(fd, " ", 1);
		ft_fprintf(fd, "%s", curr->path);
	}
	write(fd, "\n", 1);
}
