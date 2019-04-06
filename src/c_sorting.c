/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sorting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:12:38 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:12:39 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		s_b_time(t_dlist *tmp1, t_dlist *tmp2)
{
	int diff_m;
	int diff_n;

	diff_m = tmp1->buf.st_mtime - tmp2->buf.st_mtime;
	diff_n = tmp1->buf.st_mtimespec.tv_nsec - tmp2->buf.st_mtimespec.tv_nsec;
	if (diff_m < 0)
		return (0);
	else if (diff_m == 0)
	{
		if (diff_n < 0)
			return (0);
		else
			return (1);
	}
	return (1);
}

int		s_b_time_r(t_dlist *tmp1, t_dlist *tmp2)
{
	int		diff_m;
	int		diff_n;

	diff_m = tmp1->buf.st_mtime - tmp2->buf.st_mtime;
	diff_n = tmp1->buf.st_mtimespec.tv_nsec - tmp2->buf.st_mtimespec.tv_nsec;
	if (diff_m < 0)
		return (1);
	else if (diff_m == 0)
	{
		if (diff_n < 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	memclear(t_dlist *head, t_dlist *tmp)
{
	tmp = head->sub->next;
	ft_strdel(&head->sub->name);
	ft_memdel((void **)&head->sub);
	free(head->sub);
	head->sub = tmp;
}
