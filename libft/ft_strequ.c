/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:54:55 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 14:28:10 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char *s1, char const *s2)
{
	if (!ft_strcmp(s1, s2))
		return (1);
	else
		return (0);
}