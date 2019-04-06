/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 03:00:04 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 15:25:01 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;

	i = 0;
	nstr = ft_strnew(len);
	if (!nstr)
		return (NULL);
	while (i < len && s[start])
		*(nstr + i++) = *(start++ + s);
	return (nstr);
}
