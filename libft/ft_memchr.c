/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:49:00 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 13:28:22 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*chr;

	chr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (chr[i] == (unsigned char)c)
			return ((void *)&chr[i]);
		i++;
	}
	return (NULL);
}
