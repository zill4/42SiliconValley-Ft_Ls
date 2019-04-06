/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:43:21 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/25 02:07:24 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_digis(intmax_t num)
{
	int			len;

	if (!num)
		return (1);
	len = num < 0 ? 1 : 0;
	while (num)
	{
		num /= 10;
		len += 1;
	}
	return (len);
}

static void		print_sign(intmax_t num, int arg)
{
	char		sign;

	sign = 0;
	if (num < 0)
		ft_putchar('-');
	else if (num >= 0)
	{
		if (arg & PLUS)
			ft_putchar('+');
		else if (arg & SPACE)
			ft_putchar(' ');
	}
}

int				form_sign(intmax_t num, t_argu *arg)
{
	int			len;
	int			sign;
	int			num_z;
	int			num_s;

	len = 0;
	sign = (num >= 0 && (arg->flags & PLUS || arg->flags & SPACE)) ? 1 : 0;
	if (!(arg->flags & PRECISION) || arg->precision || num)
		len = num_digis(num);
	len += sign;
	num_z = num_zeros(arg, &len, (num < 0 || sign));
	num_s = num_spaces(arg->flags, arg->width, &len);
	!(arg->flags & MINUS) ? ft_putnchar(' ', num_s) : 0;
	print_sign(num, arg->flags);
	ft_putnchar('0', num_z);
	if (!(arg->flags & PRECISION && !arg->precision && !num))
		ft_putunbr((num < 0) ? (-num) : (num));
	(arg->flags & MINUS) ? ft_putnchar(' ', num_s) : 0;
	return (len);
}
