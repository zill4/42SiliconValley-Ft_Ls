/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:20:44 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 15:36:05 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_list_loader(t_dlist *head, struct dirent *de, struct stat buf)
{
	if (head->blocks == -1)
	{
		head->sub->name = ft_strdup(de->d_name);
		ft_memcpy(&(head->sub->buf), &buf, sizeof(buf));
		head->blocks += 1;
	}
	else
		append(&head->sub, de->d_name, buf);
	head->blocks += buf.st_blocks;
	return (buf.st_blocks);
}

void	ft_sorter(t_dlist *head, t_spec *spec)
{
	if (spec->flags & T_BIT)
	{
		if (spec->flags & LOWER_R_BIT)
			sort_list(head->sub, s_b_time_r);
		else
			sort_list(head->sub, s_b_time);
	}
	else
	{
		if (spec->flags & LOWER_R_BIT)
			sort_list(head->sub, s_by_name_r);
		else
			sort_list(head->sub, s_by_name);
	}
}

void	ft_sort_print(t_dlist *head, t_spec *spec)
{
	if (spec->flags & T_BIT)
	{
		if (spec->flags & T_BIT && spec->flags & LOWER_R_BIT)
			sort_list(head, s_b_time_r);
		else
			sort_list(head, s_b_time);
	}
	else
	{
		if (spec->flags & LOWER_R_BIT)
			sort_list(head, s_by_name);
		else
			sort_list(head, s_by_name_r);
	}
	print_list_r(head, spec);
}

void	load_subs(t_dlist *head, t_spec *spec)
{
	DIR				*dr;
	struct stat		buf;
	struct dirent	*de;
	char			*temp;

	if ((dr = opendir(head->name)) != NULL)
	{
		while ((de = readdir(dr)) != NULL)
		{
			temp = concat(head->name, de->d_name);
			lstat(temp, &buf);
			if (spec->flags & A_BIT)
				ft_list_loader(head, de, buf);
			else if ((ft_strcmp(de->d_name, "..") &&\
			ft_strcmp(de->d_name, ".") && check_pos(de->d_name, '.') != 0) ||\
			(ft_strchr(de->d_name, '.') == NULL))\
				ft_list_loader(head, de, buf);
			free(temp);
		}
		if (head->sub->name != NULL)
			ft_sorter(head, spec);
		closedir(dr);
	}
}
