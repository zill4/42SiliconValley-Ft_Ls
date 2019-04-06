/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 03:00:17 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 15:29:59 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*nstr;

	i = 0;
	while (s[i] <= ' ' && s[i])
		i++;
	start = i;
	while (s[i])
		i++;
	while (s[i] <= ' ' && i > start)
		i--;
	end = i;
	nstr = ft_strnew(end - start + 1);
	if (!nstr)
		return (NULL);
	i = 0;
	while (start++ <= end)
		nstr[i++] = s[start - 1];
	nstr[i] = '\0';
	return (nstr);
}
