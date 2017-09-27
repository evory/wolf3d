/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:44:14 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/22 13:10:00 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sc;
	size_t	i;

	dest = (char *)dst;
	sc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sc[i];
		i++;
	}
	dest[i] = '\0';
	return (dst);
}
