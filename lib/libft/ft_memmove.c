/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:42:56 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/22 12:16:29 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sc;

	i = 0;
	dest = (unsigned char *)dst;
	sc = (unsigned char *)src;
	if (dest > sc)
	{
		while (i < len)
		{
			dest[len - 1] = sc[len - 1];
			len--;
		}
	}
	else
		while (i < len)
		{
			dest[i] = sc[i];
			i++;
		}
	return (dst);
}
