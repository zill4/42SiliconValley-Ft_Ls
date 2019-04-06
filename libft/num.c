/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:07:30 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/25 00:37:14 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*conv_dec(uintmax_t num, int *num_digi)
{
	return (get_num_unsign(num, num_digi, 10));
}

static int		s_num(va_list ap, t_argu *arg)
{
	int			len;

	len = 0;
	if (arg->flags & J || arg->flags & Z)
		len = form_sign(va_arg(ap, intmax_t), arg);
	else if (arg->flags & LL)
		len = form_sign(va_arg(ap, long long), arg);
	else if (arg->flags & L)
		len = form_sign(va_arg(ap, long), arg);
	else if (arg->flags & HH)
		len = form_sign((char)va_arg(ap, int), arg);
	else if (arg->flags & H)
		len = form_sign((short)va_arg(ap, int), arg);
	else
		len = form_sign(va_arg(ap, int), arg);
	return (len);
}

static int		u_num(va_list ap, t_argu *arg)
{
	int			len;

	len = 0;
	if (arg->flags & J)
		len = form_usign(va_arg(ap, uintmax_t), arg, &conv_dec);
	else if (arg->flags & Z)
		len = form_usign(va_arg(ap, size_t), arg, &conv_dec);
	else if (arg->flags & LL)
		len = form_usign(va_arg(ap, unsigned long long), arg, &conv_dec);
	else if (arg->flags & L)
		len = form_usign(va_arg(ap, unsigned long), arg, &conv_dec);
	else if (arg->flags & HH)
		len = form_usign((unsigned char)va_arg(ap, unsigned int), \
				arg, &conv_dec);
	else if (arg->flags & H)
		len = form_usign((unsigned short)va_arg(ap, unsigned int), \
				arg, &conv_dec);
	else
		len = form_usign(va_arg(ap, unsigned int), arg, &conv_dec);
	return (len);
}

int				print_dec(va_list ap, t_argu *arg)
{
	int			len;
	int			flags;

	len = 0;
	flags = arg->flags;
	if (flags & D_BIT || flags & I_BIT)
		len = s_num(ap, arg);
	if (flags & U_BIT)
		len = u_num(ap, arg);
	return (len);
}
