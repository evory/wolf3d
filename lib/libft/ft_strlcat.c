/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:08:20 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/18 14:01:00 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t result;

	i = 0;
	j = 0;
	result = ft_strlen(dst) + ft_strlen(((char *)src));
	while (dst[i] != '\0' && i < size)
		i++;
	if ((size - i) == 0)
		return (i + ft_strlen((char *)src));
	while (i != (size - 1) && src[j] != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result);
}
