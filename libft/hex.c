/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 23:56:01 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/25 00:07:11 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_hexen(uintmax_t num, char *hex, char *hex_str)
{
	int			i;
	int			len;

	i = 0;
	len = !num ? 1 : 0;
	while (num)
	{
		hex[len++] = hex_str[num & 0xF];
		num >>= 4;
	}
	while (i < (len / 2))
	{
		hex[i] ^= hex[len - i - 1];
		hex[len - i - 1] ^= hex[i];
		hex[i] ^= hex[len - i - 1];
		i += 1;
	}
	return (hex);
}

static int		hex_digi(uintmax_t num)
{
	int			len;

	len = !num ? 1 : 0;
	while (num)
	{
		len++;
		num >>= 4;
	}
	return (len);
}

static char		*conv_hex(uintmax_t num, int *n_digi)
{
	char			*hex_nbr;
	char			*hex_str;

	*n_digi = hex_digi(num);
	if (!(hex_nbr = ft_memalloc(sizeof(char) * (*n_digi) + 1)))
		return (NULL);
	*hex_nbr = '0';
	if (!(hex_str = ft_strdup("0123456789ABCDEF")))
		return (NULL);
	hex_nbr = get_hexen(num, hex_nbr, hex_str);
	free(hex_str);
	return (hex_nbr);
}

int				print_hex(va_list ap, t_argu *arg)
{
	int			len;

	if (arg->flags & P_BIT)
		len = form_usign((uintmax_t)va_arg(ap, void *), arg, &conv_hex);
	else if (arg->flags & J)
		len = form_usign(va_arg(ap, uintmax_t), arg, &conv_hex);
	else if (arg->flags & Z)
		len = form_usign(va_arg(ap, size_t), arg, &conv_hex);
	else if (arg->flags & LL)
		len = form_usign(va_arg(ap, unsigned long long), arg, &conv_hex);
	else if (arg->flags & L)
		len = form_usign(va_arg(ap, unsigned long), arg, &conv_hex);
	else if (arg->flags & HH)
		len = form_usign((unsigned char)va_arg(ap, unsigned int), \
				arg, &conv_hex);
	else if (arg->flags & H)
		len = form_usign((unsigned short)va_arg(ap, unsigned int), \
				arg, &conv_hex);
	else
		len = form_usign(va_arg(ap, unsigned int), arg, &conv_hex);
	return (len);
}
