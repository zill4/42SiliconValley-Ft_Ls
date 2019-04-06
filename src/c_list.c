/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:32:43 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 13:46:37 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	del_list(t_dlist *list)
{
	while (list)
	{
		if (list->sub)
			del_list(list->sub);
		ft_strdel(&list->name);
		ft_memdel((void **)list);
		free(list);
		list = list->next;
	}
}

void	lstdel(t_dlist **list)
{
	t_dlist		*temp;

	if ((*list))
	{
		temp = (*list)->next;
		(*list)->next = NULL;
		ft_strdel(&(*list)->name);
		ft_memdel((void**)&(*list));
		lstdel(&(temp));
	}
}

void	append(t_dlist **head, char *name, struct stat buf)
{
	t_dlist *new;
	t_dlist *last;

	last = *head;
	new = malloc(sizeof(t_dlist));
	new->next = NULL;
	new->blocks = -1;
	new->name = ft_strdup(name);
	new->sub = NULL;
	ft_memcpy(&(new->buf), &buf, sizeof(buf));
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

void	append_d(t_dlist **head, char *name, struct stat buf)
{
	t_dlist *new;
	t_dlist *last;

	last = *head;
	new = malloc(sizeof(t_dlist));
	new->next = NULL;
	new->blocks = -1;
	new->name = ft_strdup(name);
	new->sub = new_list();
	ft_memcpy(&(new->buf), &buf, sizeof(buf));
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}
