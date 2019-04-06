/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LS.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:11:45 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 17:17:42 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		read_files(char *name, t_dlist **head, t_spec *spec)
{
	struct stat		buf;

	lstat(name, &buf);
	if (S_ISDIR(buf.st_mode))
	{
		if ((*head)->name == NULL)
			(*head) = new_node(name, buf);
		else
			append_d(head, name, buf);
		next_dir(name, (*head), spec);
		spec->dirs += 1;
	}
	else
	{
		if (S_ISREG(buf.st_mode) && is_in_dir(name))
			check_file(head, spec, buf, name);
		else
		{
			ft_printf("%s no file or directory\n", name);
			return (0);
		}
	}
	return (1);
}

t_spec	*new_spec(void)
{
	t_spec	*spec;

	spec = malloc(sizeof(t_spec));
	spec->flags = 0;
	spec->dirs = 0;
	return (spec);
}

int		c_main(int argc, t_dlist **head, t_spec *spec)
{
	t_dlist			*tmp;
	struct stat		buf;

	tmp = NULL;
	if (argc == 1 || (*head)->name == NULL)
	{
		lstat(".", &buf);
		*head = new_node(".", buf);
		next_dir((*head)->name, (*head), spec);
	}
	if ((spec->flags & F_BIT))
		run_file(head, spec);
	if (!(*head))
		return (0);
	if (ft_strcmp((*head)->name, ".") == 0)
	{
		load_subs((*head), spec);
		print_dir((*head), spec);
		tmp = (*head);
		*head = (*head)->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_dlist	*head;
	int		args;
	t_spec	*spec;

	args = 0;
	head = new_list();
	head->sub = new_list();
	spec = new_spec();
	while (++args < argc)
	{
		if (argv[args][0] == '-')
			set_flags(argv[args], spec);
		else if (!(read_files(argv[args], &head, spec)))
			return (-1);
		if (spec->flags & ERROR)
			return (ft_printf("ft_ls: illegal option -- %s\nusage:\
			ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]\
			[file ...]\n", argv[args]));
	}
	if (!(c_main(argc, &head, spec)))
		return (0);
	ft_sort_print(head, spec);
	del_list(head);
	return (0);
}
