/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:58:26 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/18 19:28:22 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (sign * res);
}
