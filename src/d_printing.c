/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_printing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:47:43 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 17:42:28 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_file(char *name, t_spec *spec)
{
	struct stat buf;

	lstat(name, &buf);
	if (spec->flags & _L_BIT)
	{
		mode_print(buf.st_mode, -1);
		ft_printf(" %hu ", buf.st_nlink);
		ft_printf("%-5s ", getpwuid(buf.st_uid)->pw_name);
		ft_printf("%s ", getgrgid(buf.st_gid)->gr_name);
		ft_printf("%6lld ", buf.st_size);
		ft_printf("%.12s ", 4 + (ctime(&buf.st_mtime)));
	}
	ft_printf("%s\n", name);
	ft_printf("\n");
}

void	print_begin(t_dlist **head, t_spec *spec)
{
	if ((ft_strcmp((*head)->name, ".") && ((*head)->next)) || (spec->dirs > 1))
		ft_printf("%s:\n", (*head)->name);
	if (spec->flags & _L_BIT && !(spec->flags & F_BIT))
		ft_printf("Total %d\n", (*head)->blocks);
	if ((*head)->sub->name == NULL)
		(*head)->sub = (*head)->sub->next;
}

void	print_mid(t_dlist **head, t_spec *spec)
{
	t_dlist *tmp;

	tmp = NULL;
	while ((*head)->sub->next)
	{
		if (spec->flags & _L_BIT)
			print_details(*head);
		ft_printf("%s\n", (*head)->sub->name);
		tmp = (*head)->sub->next;
		ft_memdel((void **)&(*head)->sub);
		free((*head)->sub);
		(*head)->sub = tmp;
	}
}

void	print_end(t_dlist **head, t_spec *spec)
{
	if (spec->flags & _L_BIT)
		print_details(*head);
	ft_printf("%s\n ", (*head)->sub->name);
	if (!(spec->flags & F_BIT))
		ft_strdel(&(*head)->sub->name);
	ft_memdel((void **)&(*head)->sub);
	del_list((*head)->sub);
	free((*head)->sub);
	ft_printf("\n");
}

void	print_dir(t_dlist *head, t_spec *spec)
{
	if ((head->sub == NULL || head->blocks == -1) & (!(spec->flags & F_BIT)))
		return ;
	if (head->sub == NULL && spec->flags & F_BIT)
	{
		print_file(head->name, spec);
		return ;
	}
	print_begin(&head, spec);
	print_mid(&head, spec);
	print_end(&head, spec);
}
