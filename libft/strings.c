/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 01:02:08 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/25 01:10:59 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			print_spaces(int width, int len, int att)
{
	while ((width - len) > 0)
	{
		ft_putchar(((att & ZERO) && !(att & MINUS)) ? '0' : ' ');
		len++;
	}
	return (len);
}

int			print_str(va_list ap, t_argu *arg)
{
	int		len;
	char	*str;
	char	*cpy;

	if (!(str = va_arg(ap, char *)))
		str = ft_strdup("(null)");
	if (arg->flags & PRECISION)
	{
		if (!(cpy = (char*)malloc(arg->precision)))
			return (0);
		cpy = ft_strncpy(cpy, str, arg->precision);
		str = cpy;
	}
	len = ft_strlen(str);
	if (!(arg->flags & MINUS))
		len = print_spaces(arg->width, len, arg->flags);
	ft_putstr(str);
	if (arg->flags & MINUS)
		len = print_spaces(arg->width, len, arg->flags);
	return (len);
}

int			print_char(va_list ap, t_argu *arg)
{
	int		len;
	char	c;

	c = va_arg(ap, int);
	len = 1;
	if (!(arg->flags & MINUS))
		len = print_spaces(arg->width, len, arg->flags);
	ft_putchar(c);
	if (arg->flags & MINUS)
		len = print_spaces(arg->width, len, arg->flags);
	return (len);
}
