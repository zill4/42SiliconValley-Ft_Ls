/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 00:53:15 by jcrisp            #+#    #+#             */
/*   Updated: 2019/03/25 02:06:58 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		spec_check(char c, char *str)
{
	int			i;

	i = 0;
	if (c == 'U')
		c = 'u';
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

static int		get_spec(char c, t_argu *arg, char *spec)
{
	int			*tbl;
	int			specifier;

	tbl = ft_memalloc(sizeof(int) * SPECI_SIZE);
	tbl[S] = S_BIT;
	tbl[P] = P_BIT;
	tbl[D] = D_BIT;
	tbl[I] = I_BIT;
	tbl[O] = O_BIT;
	tbl[U] = U_BIT;
	tbl[LOWER_X] = LOW_X_BIT;
	tbl[UPPER_X] = UPP_X_BIT;
	tbl[C] = C_BIT;
	if (((specifier = spec_check(c, spec)) != -1) && c)
		arg->flags |= tbl[specifier];
	free(tbl);
	return (specifier);
}

int				spec_buff(va_list ap, char **string, t_argu *arg)
{
	int			specifier;
	int			valid;
	char		*conv;

	arg->flags = 0;
	if (!(conv = (char *)malloc(sizeof(char) * SPECI_SIZE)))
		return (0);
	conv = ft_strncpy(conv, SPECIFIERS, SPECI_SIZE);
	specifier = PRINTF_FAILURE;
	while (**string)
	{
		if ((spec_check(**string, conv) != -1) && \
			(specifier = get_spec(**string, arg, conv)))
			break ;
		if (!(valid = get_atts(string, ap, arg)))
			break ;
	}
	free(conv);
	return (specifier);
}
