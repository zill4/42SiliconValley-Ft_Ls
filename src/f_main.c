/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:11:59 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:13:58 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*take_dir(char *name)
{
	char	*result;
	int		i;
	int		len;

	if (!name)
		return (NULL);
	i = 0;
	len = ft_strlen(name);
	result = malloc(len);
	while (len--)
	{
		if (name[len] == '/')
			break ;
	}
	if (len < 0)
		return ("./");
	while (i != len)
	{
		result[i] = name[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*take_name(char *name)
{
	char	*result;
	int		i;
	int		len;

	if (!name)
		return (NULL);
	i = 0;
	len = ft_strlen(name);
	result = malloc(len);
	while (len--)
	{
		if (name[len] == '/')
			break ;
	}
	++len;
	while (name[len])
	{
		result[i] = name[len++];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	run_file(t_dlist **head, t_spec *spec)
{
	t_dlist *tmp;

	if (spec->flags & T_BIT)
	{
		if (spec->flags & T_BIT && spec->flags & LOWER_R_BIT)
			sort_list((*head)->sub, s_b_time_r);
		else
			sort_list((*head)->sub, s_b_time);
	}
	else
	{
		if (spec->flags & LOWER_R_BIT)
			sort_list((*head)->sub, s_by_name_r);
		else
			sort_list((*head)->sub, s_by_name);
	}
	print_dir(*head, spec);
	tmp = (*head)->next;
	del_list((*head)->sub);
	ft_strdel(&(*head)->name);
	*head = tmp;
}

void	check_file(t_dlist **head, t_spec *spec, struct stat buf, char *name)
{
	if (!(spec->flags & F_BIT))
	{
		if ((*head)->name == NULL)
		{
			(*head)->name = ft_strdup(".");
			ft_memcpy(&(*head)->sub->buf, &buf, sizeof(buf));
			(*head)->sub->name = name;
		}
		else
		{
			push(&(*head), ".", buf);
			append(&(*head)->sub, name, buf);
		}
	}
	else
		append(&(*head)->sub, name, buf);
	spec->dirs += 1;
	spec->flags |= F_BIT;
}
