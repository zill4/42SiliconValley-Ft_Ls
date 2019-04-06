/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:49:45 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 13:56:26 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_src;
	char	*p_dst;

	i = 0;
	p_src = (char *)src;
	p_dst = (char *)dst;
	if (p_src > p_dst)
		while (i < len)
		{
			*(p_dst + i) = *(p_src + i);
			i++;
		}
	else
		while (len-- > 0)
			*(p_dst + len) = *(p_src + len);
	return (dst);
}
