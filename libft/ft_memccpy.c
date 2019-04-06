/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:48:52 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 15:35:35 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	count;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	count = 0;
	while (count < n)
	{
		d[count] = s[count];
		if (d[count] == c)
			return ((void*)&d[count + 1]);
		count++;
	}
	return (NULL);
}
