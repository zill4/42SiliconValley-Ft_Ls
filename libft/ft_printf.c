/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 23:53:26 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/24 23:55:40 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		print_no_spec(char c, t_argu *arg)
{
	int			len;

	if (!(arg->flags & MINUS))
		len = print_spaces(arg->width, 1, arg->flags);
	ft_putchar(c);
	if (arg->flags & MINUS)
		len = print_spaces(arg->width, 1, arg->flags);
	return (len);
}

static int		print_spec(char string, va_list ap, t_argu *arg, int i)
{
	int			print;

	if (i == S)
		print = print_str(ap, arg);
	else if (i == D || i == I || i == U)
		print = print_dec(ap, arg);
	else if (i == O)
		print = print_oct(ap, arg);
	else if (i == P || i == LOWER_X || i == UPPER_X)
		print = print_hex(ap, arg);
	else if (i == C)
		print = print_char(ap, arg);
	else
		print = print_no_spec(string, arg);
	return (print);
}

static int		print_buff(const char *string[], va_list ap)
{
	int			specifier;
	t_argu		arg;

	arg.flags = 0;
	arg.width = 0;
	arg.precision = 0;
	specifier = spec_buff(ap, (char **)string, &arg);
	if (!**string)
		return (-1);
	return (print_spec((char)**string, ap, &arg, specifier));
}

int				ft_printf(const char *string, ...)
{
	int			count;
	int			len;
	va_list		ap;

	len = 0;
	count = 0;
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
		{
			string += 1;
			if ((len = print_buff(&string, ap)) == PRINTF_FAILURE)
				break ;
			count += len;
		}
		else
		{
			ft_putchar(*string);
			count += 1;
		}
		string += 1;
	}
	va_end(ap);
	return (count);
}
