/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:06:35 by jcrisp            #+#    #+#             */
/*   Updated: 2019/04/05 17:43:05 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		check_pos(char *str, char c)
{
	char	*tmp;
	int		pos;

	pos = -1;
	tmp = ft_strchr(str, c);
	pos = (int)(tmp - str);
	return (pos);
}

char	*concat(const char *s1, const char *s2)
{
	char	*temp;
	char	*result;

	temp = malloc(ft_strlen(s1) + 2);
	ft_strcpy(temp, s1);
	ft_strcat(temp, "/");
	result = malloc(ft_strlen(temp) + ft_strlen(s2) + 1);
	ft_strcpy(result, temp);
	ft_strcat(result, s2);
	free(temp);
	return (result);
}

void	mode_print(int mode, int i)
{
	char			c;
	static char		temp[10];

	while (++i < 9)
		temp[i] = (mode & (1 << (8 - i))) ? BUF[i] : '-';
	temp[i] = '\0';
	if ((mode & S_IFDIR) == S_IFDIR)
		c = 'd';
	else if ((mode & S_IFLNK) == S_IFLNK)
		c = 'l';
	else if ((mode & S_IFBLK) == S_IFBLK)
		c = 'b';
	else if ((mode & S_IFCHR) == S_IFCHR)
		c = 'c';
	else if ((mode & S_IFIFO) == S_IFIFO)
		c = 'p';
	else if ((mode & S_IFSOCK) == S_IFSOCK)
		c = 's';
	else
		c = '-';
	ft_printf("%c%s", c, temp);
}
