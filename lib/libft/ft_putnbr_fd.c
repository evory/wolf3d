/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:03:55 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/17 22:17:42 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_valmax_fd(int fd)
{
	char	*str;

	str = "2147483648";
	ft_putstr_fd(str, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_valmax_fd(fd);
	}
	if (n < 0 && n > -2147483648)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9 && n >= 0)
	{
		ft_putchar_fd(n + 48, fd);
	}
}
