/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:30:23 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 17:41:22 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

typedef struct		s_spec
{
	int				flags;
	int				dirs;
}					t_spec;

typedef struct		s_dlist
{
	char			*name;
	int				blocks;
	struct stat		buf;
	struct s_dlist	*sub;
	struct s_dlist	*next;
}					t_dlist;

# define BUF "rwxrwxrwx"
# define FT_BIT(x) (1 << (x))
# define SPECS "lRart"
# define _L				(0)
# define UPPER_R		(1)
# define A				(2)
# define LOWER_R		(3)
# define T				(4)
# define E				(5)
# define F				(6)
# define _D				(7)
# define _L_BIT			(FT_BIT(0))
# define UPPER_R_BIT	(FT_BIT(1))
# define A_BIT			(FT_BIT(2))
# define LOWER_R_BIT	(FT_BIT(3))
# define T_BIT			(FT_BIT(4))
# define ERROR			(FT_BIT(5))
# define F_BIT			(FT_BIT(6))
# define _D_BIT			(FT_BIT(7))

void				load_subs(t_dlist *head, t_spec *spec);
void				ft_sort_print(t_dlist *head, t_spec *spec);
void				ft_sorter(t_dlist *head, t_spec *spec);
int					ft_list_loader(t_dlist *head, \
		struct dirent *de, struct stat buf);
void				mode_print(int mode, int i);
char				*concat(const char *s1, const char *s2);
int					check_pos(char *str, char c);
int					c_main(int argc, t_dlist **head, t_spec *spec);
t_spec				*new_spec(void);
int					read_files(char *name, t_dlist **head, t_spec *spec);
void				push(t_dlist **head_ref, char *name, struct stat buf);
void				is_file(t_dlist *head, struct stat buf, char *name);
int					is_in_dir(char *name);
char				*take_dir(char *name);
char				*take_name(char *name);
void				run_file(t_dlist **head, t_spec *spec);
void				check_file(t_dlist **head, t_spec *spec, \
		struct stat buf, char *name);
void				print_details(t_dlist *head);
void				print_list(t_dlist *head, t_spec *spec);
void				print_list_r(t_dlist *head, t_spec *spec);
void				ft_bufdel(struct stat **as);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
t_dlist				*new_list(void);
t_dlist				*new_node(char *name, struct stat buf);
void				print_dir(t_dlist *head, t_spec *spec);
void				memclear(t_dlist *head, t_dlist *tmp);
void				print_file(char *name, t_spec *spec);
int					s_b_time_r(t_dlist *tmp1, t_dlist *tmp2);
int					s_b_time(t_dlist *tmp1, t_dlist *tmp2);
void				append_d(t_dlist **head, char *name, struct stat buf);
void				append(t_dlist **head, char *name, struct stat buf);
void				lstdel(t_dlist **list);
void				del_list(t_dlist *list);
int					s_by_name(t_dlist *tmp1, t_dlist *tmp2);
int					s_by_name_r(t_dlist *tmp1, t_dlist *tmp2);
void				swap_info(t_dlist *one, t_dlist *second);
int					c_list(t_dlist *lst);
t_dlist				*sort_list(t_dlist *lst, int (*cmp)(t_dlist *, t_dlist *));
int					check_name(struct dirent *de);
int					check_file_name(struct dirent *de);
void				director(char *name, struct dirent *de, t_dlist **head,\
		t_spec *spec);
void				set_flags(char *str, t_spec *spec);
int					check_format(char *str, t_spec *spec);
int					check_string(char *str, t_spec *spec);
void				next_dir(char *name, t_dlist *head, t_spec *spec);
void				check_bit(char *name, struct dirent *de, t_dlist **head,\
		t_spec *spec);

#endif
