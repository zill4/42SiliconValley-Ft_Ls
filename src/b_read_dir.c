/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_read_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:12:30 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:12:31 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	director(char *name, struct dirent *de, t_dlist **head, t_spec *spec)
{
	struct stat	buf;
	char		*temp;

	lstat(name, &buf);
	temp = concat(name, de->d_name);
	append_d(head, temp, buf);
	next_dir(temp, *(head), spec);
	free(temp);
}

int		check_file_name(struct dirent *de)
{
	if ((ft_strchr(de->d_name, '.') == 0 && ft_strlen(de->d_name) > 1 && \
	!(ft_strcmp(de->d_name, ".."))) || (ft_strchr(de->d_name, '.') == NULL) || \
	(ft_strchr(de->d_name, '.') != NULL && ft_strcmp(de->d_name, "..") && \
	ft_strcmp(de->d_name, ".")))
		return (1);
	else
		return (0);
}

int		check_name(struct dirent *de)
{
	if ((ft_strcmp(de->d_name, "..") && ft_strcmp(de->d_name, ".") && \
		check_pos(de->d_name, '.') != 0) || \
		(ft_strchr(de->d_name, '.') == NULL))
		return (1);
	else
		return (0);
}
