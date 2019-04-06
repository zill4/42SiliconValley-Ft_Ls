/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sorting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:55:31 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:15:34 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			s_by_name(t_dlist *tmp1, t_dlist *tmp2)
{
	int diff_m;

	diff_m = ft_strcmp(tmp1->name, tmp2->name);
	if (diff_m <= 0)
		return (1);
	else
		return (0);
}

int			s_by_name_r(t_dlist *tmp1, t_dlist *tmp2)
{
	int		diff_m;

	diff_m = ft_strcmp(tmp1->name, tmp2->name);
	if (diff_m > 0)
		return (1);
	else
		return (0);
}

void		swap_info(t_dlist *one, t_dlist *second)
{
	char			*str_tmp;
	struct stat		buf_tmp;

	str_tmp = one->name;
	buf_tmp = one->buf;
	one->name = second->name;
	one->buf = second->buf;
	second->name = str_tmp;
	second->buf = buf_tmp;
}

int			c_list(t_dlist *lst)
{
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (0);
	return (1);
}

t_dlist		*sort_list(t_dlist *lst, int (*cmp)(t_dlist *, t_dlist *))
{
	t_dlist *tmp;
	t_dlist *tmp2;

	if (!(c_list(lst)))
		return (NULL);
	tmp = lst;
	tmp2 = lst;
	while (tmp->next)
	{
		while (tmp2->next)
		{
			if (cmp(tmp, tmp2) == 1)
				swap_info(tmp, tmp2);
			tmp2 = tmp2->next;
		}
		tmp2 = lst;
		tmp = tmp->next;
	}
	while (tmp2->next)
	{
		if (cmp(tmp, tmp2) == 1)
			swap_info(tmp, tmp2);
		tmp2 = tmp2->next;
	}
	return (lst);
}
