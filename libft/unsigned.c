/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 01:11:58 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/25 01:28:49 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		non_dec(uintmax_t num, int arg, int prec)
{
	if (arg & O_BIT && arg & HASH && (num || \
		(!num && arg & PRECISION && !prec)))
		return (1);
	else if (((arg & LOW_X_BIT || arg & UPP_X_BIT) && \
		arg & HASH && num) || arg & P_BIT)
		return (2);
	return (0);
}

int				num_zeros(t_argu *arg, int *len, int sign)
{
	int			n_zeros;

	n_zeros = 0;
	if (arg->flags & PRECISION && arg->precision > *len - sign)
	{
		n_zeros += arg->precision - *len + sign;
		*len += n_zeros;
	}
	if (arg->flags & WIDTH && arg->flags & ZERO && \
		!(arg->flags & MINUS) && !(arg->flags & PRECISION) && \
		arg->width > *len)
	{
		n_zeros += arg->width - *len;
		*len += n_zeros;
	}
	return (n_zeros);
}

int				num_spaces(int arg, int wid, int *len)
{
	int			n_spaces;

	n_spaces = 0;
	if (arg & WIDTH && (!(arg & ZERO) || arg & MINUS || \
		arg & PRECISION) && wid > *len)
	{
		n_spaces += wid - *len;
		*len += n_spaces;
	}
	return (n_spaces);
}

char			*get_num_unsign(uintmax_t num, int *n_digis, int base)
{
	int			len;
	char		*str;
	uintmax_t	r;

	len = 0;
	r = num;
	*n_digis = (!num) ? 1 : 0;
	while (r)
	{
		r /= base;
		*n_digis += 1;
	}
	if (!(str = (char *)malloc(sizeof(char) * (*n_digis))))
		return (NULL);
	*str = '0';
	len = (!num) ? 1 : 0;
	while (num)
	{
		r = num % base;
		num /= base;
		str[len++] = r + '0';
	}
	str[len] = '\0';
	str = ft_strrev(str);
	return (str);
}

int				form_usign(uintmax_t num, t_argu *arg, \
		char *(*conv)(uintmax_t, int *))
{
	int			len;
	int			sign;
	int			n_zeros;
	int			n_spaces;
	char		*n_conv;

	n_conv = conv(num, &len);
	sign = non_dec(num, arg->flags, arg->precision);
	if (arg->flags & LOW_X_BIT || arg->flags & P_BIT)
		ft_lower_str(n_conv);
	(arg->flags & PRECISION && !arg->precision && !num) ? len = 0 : len;
	len += sign;
	n_zeros = num_zeros(arg, &len, (sign == 2) ? 2 : 0);
	n_spaces = num_spaces(arg->flags, arg->width, &len);
	!(arg->flags & MINUS) ? ft_putnchar(' ', n_spaces) : 0;
	non_dec(num, arg->flags, arg->precision) ? ft_putchar('0') : 0;
	if (non_dec(num, arg->flags, arg->precision) > 1)
		arg->flags & UPP_X_BIT ? ft_putchar('X') : ft_putchar('x');
	ft_putnchar('0', n_zeros);
	if (!(arg->flags & PRECISION && !arg->precision && !num))
		ft_putstr(n_conv);
	free(n_conv);
	(arg->flags & MINUS) ? ft_putnchar(' ', n_spaces) : 0;
	return (len);
}
