/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:20:03 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/15 20:00:19 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*sc;

	i = 0;
	dest = (char *)dst;
	sc = (char *)src;
	while (i < n)
	{
		dest[i] = sc[i];
		if (sc[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
