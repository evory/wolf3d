/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:35:39 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/11 13:52:05 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		while (i <= size)
		{
			mem[i] = 0;
			i++;
		}
	}
	if (mem == NULL)
		return (0);
	return ((void *)mem);
}
