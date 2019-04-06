/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:59:57 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 15:19:33 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t j;
	size_t c;

	j = 0;
	c = 0;
	if (haystack[j] == needle[j] && haystack[j] == '\0')
		return ((char*)&haystack[j]);
	while (haystack[j])
	{
		c = j;
		while (haystack[c] == needle[c - j] && haystack[c])
			c++;
		if (needle[c - j] == '\0')
			return ((char*)&haystack[j]);
		j++;
	}
	return (NULL);
}
