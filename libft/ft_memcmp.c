/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:49:10 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 13:41:38 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*s1_p;
	unsigned char		*s2_p;

	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (*(char *)(s1_p + i) != *(char *)(s2_p + i))
			break ;
	if (i == n)
		return (0);
	return (*(unsigned char *)(s1_p + i) - *(unsigned char *)(s2_p + i));
}
