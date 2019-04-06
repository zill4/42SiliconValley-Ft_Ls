/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:59:54 by jcrisp            #+#    #+#             */
/*   Updated: 2018/11/27 11:16:19 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_stralloc(char **str, char **line, int fd, int val)
{
	char	*new;
	int		i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		new = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = new;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (val == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[255];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			val;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((val = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[val] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (val < 0)
		return (-1);
	else if (val == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_stralloc(str, line, fd, val));
}
