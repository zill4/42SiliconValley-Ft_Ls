/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_printing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:12:16 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 16:13:07 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_list_r(t_dlist *head, t_spec *spec)
{
	if (!head)
		return ;
	if (head->next)
		print_list_r(head->next, spec);
	load_subs(head, spec);
	print_dir(head, spec);
}

void	print_list(t_dlist *head, t_spec *spec)
{
	if (!head)
		return ;
	while (head->next)
	{
		load_subs(head, spec);
		print_dir(head, spec);
		head = head->next;
	}
	load_subs(head, spec);
	print_dir(head, spec);
}

void	print_details(t_dlist *head)
{
	mode_print(head->sub->buf.st_mode, -1);
	ft_printf(" %hu ", head->sub->buf.st_nlink);
	ft_printf("%-5s ", getpwuid(head->sub->buf.st_uid)->pw_name);
	ft_printf("%s ", getgrgid(head->sub->buf.st_gid)->gr_name);
	ft_printf("%6lld ", head->sub->buf.st_size);
	ft_printf("%.12s ", 4 + (ctime(&head->sub->buf.st_mtime)));
}
