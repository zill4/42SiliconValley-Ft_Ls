/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gucci_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:12:48 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:12:49 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	push(t_dlist **head_ref, char *name, struct stat buf)
{
	t_dlist		*new_node;

	new_node = malloc(sizeof(t_dlist));
	new_node->blocks = -1;
	new_node->name = ft_strdup(name);
	new_node->sub = NULL;
	ft_memcpy(&(new_node->buf), &buf, sizeof(buf));
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void	is_file(t_dlist *head, struct stat buf, char *name)
{
	if (head->name == NULL)
	{
		ft_memcpy(&(head->buf), &buf, sizeof(buf));
		append(&head->sub, name, buf);
	}
	else
		append(&head->sub, name, buf);
}

int		is_in_dir(char *name)
{
	DIR				*dr;
	struct dirent	*de;
	char			*namer;
	char			*temp;

	temp = name;
	if (check_pos(name, '/') < 0)
		temp = concat(".", name);
	else
		name = take_name(name);
	namer = take_dir(temp);
	if ((dr = opendir(namer)))
	{
		while ((de = readdir(dr)) != NULL)
		{
			if (ft_strcmp(de->d_name, name) == 0)
				return (1);
		}
	}
	return (0);
}
