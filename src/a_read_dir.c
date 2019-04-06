/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_read_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:38:29 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:14:42 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	check_bit(char *name, struct dirent *de, t_dlist **head, t_spec *spec)
{
	if (spec->flags & A_BIT)
	{
		if (check_file_name(de))
			director(name, de, head, spec);
	}
	else
	{
		if (check_name(de))
			director(name, de, head, spec);
	}
}

void	next_dir(char *name, t_dlist *head, t_spec *spec)
{
	DIR				*dr;
	struct dirent	*de;
	struct stat		buf;
	char			*temp;

	dr = opendir(name);
	if (dr == NULL)
		return ;
	while ((de = readdir(dr)) != NULL)
	{
		temp = concat(name, de->d_name);
		lstat(temp, &buf);
		free(temp);
		if (spec->flags & UPPER_R_BIT)
			if (S_ISDIR(buf.st_mode))
				check_bit(name, de, &head, spec);
	}
	closedir(dr);
}

int		check_string(char *str, t_spec *spec)
{
	if (!str)
	{
		ft_printf("ERROR Bad String!\n");
		spec->flags |= ERROR;
		return (-1);
	}
	return (1);
}

int		check_format(char *str, t_spec *spec)
{
	if (str[0] != '-')
	{
		ft_printf("ERROR Bad Flag format\n");
		spec->flags |= ERROR;
		return (-1);
	}
	return (1);
}

void	set_flags(char *str, t_spec *spec)
{
	int i;

	i = 0;
	if (!(check_string(str, spec)) || !(check_format(str, spec)))
		return ;
	while (str[++i])
	{
		if (str[i] == 'l')
			spec->flags |= _L_BIT;
		else if (str[i] == 'a')
			spec->flags |= A_BIT;
		else if (str[i] == 'r')
			spec->flags |= LOWER_R_BIT;
		else if (str[i] == 'R')
			spec->flags |= UPPER_R_BIT;
		else if (str[i] == 't')
			spec->flags |= T_BIT;
		else
			spec->flags |= ERROR;
	}
}
