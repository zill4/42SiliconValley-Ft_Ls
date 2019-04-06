/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:37:39 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/25 00:40:19 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*conv_oct(uintmax_t num, int *dig)
{
	return (get_num_unsign(num, dig, 8));
}

int				print_oct(va_list ap, t_argu *arg)
{
	int			len;

	if (arg->flags & J)
		len = form_usign(va_arg(ap, uintmax_t), arg, &conv_oct);
	else if (arg->flags & Z)
		len = form_usign(va_arg(ap, size_t), arg, &conv_oct);
	else if (arg->flags & LL)
		len = form_usign(va_arg(ap, unsigned long long), arg, &conv_oct);
	else if (arg->flags & L)
		len = form_usign(va_arg(ap, unsigned long), arg, &conv_oct);
	else if (arg->flags & HH)
		len = form_usign((unsigned char)va_arg(ap, unsigned int),\
				arg, &conv_oct);
	else if (arg->flags & H)
		len = form_usign((unsigned short)va_arg(ap, unsigned int),\
				arg, &conv_oct);
	else
		len = form_usign(va_arg(ap, unsigned int), arg, &conv_oct);
	return (len);
}
