/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 23:03:01 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/24 23:45:44 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_flags(char flg, t_argu *arg)
{
	flg == '#' ? arg->flags |= HASH : 0;
	flg == '0' ? arg->flags |= ZERO : 0;
	flg == '-' ? arg->flags |= MINUS : 0;
	flg == ' ' ? arg->flags |= SPACE : 0;
	flg == '+' ? arg->flags |= PLUS : 0;
	return (flg == '#' || flg == '0' || flg == '-' || flg == ' ' || flg == '+');
}

static int		get_width(va_list ap, char *string, t_argu *arg)
{
	int			width;
	char		*num;

	width = 0;
	if (string[width] == '*')
	{
		arg->width = va_arg(ap, int);
		if (arg->width < 0)
		{
			arg->width *= -1;
			arg->flags |= MINUS;
		}
		width = 1;
	}
	else
	{
		while (ft_isdigit(string[width]))
			width++;
		if (!width || !(num = ft_strsub(string, 0, width)))
			return (0);
		arg->width = ft_atoi(num);
		free(num);
	}
	return (width);
}

static int		get_prec(va_list ap, char *string, t_argu *arg)
{
	int			prec;
	char		*num;

	prec = 0;
	if (string[0] == '.')
	{
		prec = 1;
		if (string[prec] == '*')
		{
			arg->precision = va_arg(ap, int);
			prec++;
		}
		else
		{
			while (ft_isdigit(string[prec]))
				prec++;
			if (!(num = ft_strsub(string, 1, prec)))
				return (0);
			arg->precision = (prec != 1) ? ft_atoi(num) : 0;
			free(num);
		}
	}
	return (prec);
}

static int		get_mod(char *string, t_argu *arg)
{
	int			len;

	len = 0;
	while (string[len] == 'h' || string[len] == 'l' \
			|| string[len] == 'j' || string[len] == 'z')
	{
		if (string[len] == 'h')
			string[len + 1] == 'h' ? (arg->flags |= HH) : (arg->flags |= H);
		if (string[len] == 'l')
			string[len + 1] == 'l' ? (arg->flags |= LL) : (arg->flags |= L);
		if (arg->flags == HH || arg->flags == LL)
			len++;
		if (string[len] == 'j')
			arg->flags |= J;
		if (string[len] == 'z')
			arg->flags |= Z;
		len++;
	}
	return (len);
}

int				get_atts(char **string, va_list ap, t_argu *arg)
{
	char		*init;
	int			f_width;

	init = *string;
	while (get_flags(**string, arg))
		(*string)++;
	while ((f_width = get_width(ap, *string, arg)))
	{
		arg->flags |= WIDTH;
		(*string) += f_width;
	}
	while ((f_width = get_prec(ap, *string, arg)))
	{
		if (arg->precision >= 0)
			arg->flags |= PRECISION;
		(*string) += f_width;
	}
	while ((f_width = get_mod(*string, arg)))
		(*string) += f_width;
	return (*string > init);
}
