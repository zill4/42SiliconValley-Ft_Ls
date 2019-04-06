/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:51:44 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/08 14:14:41 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (-9 <= n && n <= 9)
	{
		ft_putchar_fd(n * sign + '0', fd);
	}
	else
	{
		ft_putnbr_fd((n / 10) * sign, fd);
		ft_putnbr_fd((n % 10) * sign, fd);
	}
}
