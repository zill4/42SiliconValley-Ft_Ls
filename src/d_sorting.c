/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_sorting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:12:56 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:15:59 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dlist		*new_node(char *name, struct stat buf)
{
	t_dlist *new;

	new = malloc(sizeof(t_dlist));
	new->next = NULL;
	new->sub = NULL;
	ft_memcpy(&(new->buf), &buf, sizeof(buf));
	new->name = ft_strdup(name);
	return (new);
}

t_dlist		*new_list(void)
{
	t_dlist *new;

	new = malloc(sizeof(t_dlist));
	new->name = NULL;
	new->next = NULL;
	new->sub = NULL;
	new->blocks = 0;
	return (new);
}

void		ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}

void		ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

void		ft_bufdel(struct stat **as)
{
	ft_memdel((void **)as);
}
