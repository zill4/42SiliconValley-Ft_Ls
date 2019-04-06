/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:56:56 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 14:50:38 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned	i;
	char		*nstr;

	i = 0;
	nstr = ft_strnew(ft_strlen((char*)s));
	if (!nstr)
		return (NULL);
	while (s[i])
	{
		nstr[i] = f(s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
