/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:48:09 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/17 22:07:47 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen(int i)
{
	int	nb;

	nb = 0;
	while (i != 0)
	{
		i = i / 10;
		nb++;
	}
	return (nb);
}

char			*ft_itoa(int n)
{
	char	*alpha;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	count = ft_nblen(n);
	if (!(alpha = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	if (n < 0)
	{
		alpha[0] = '-';
		n = n * -1;
		count++;
	}
	alpha[count] = '\0';
	while (n != 0)
	{
		alpha[--count] = ((n % 10) + '0');
		n = n / 10;
	}
	return (alpha);
}
