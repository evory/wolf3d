/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:24:16 by bbrandt           #+#    #+#             */
/*   Updated: 2017/01/25 22:41:51 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *l, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*l)
		return ((char *)big);
	while (big[i] && len > 0)
	{
		j = 0;
		if (len < ft_strlen((char *)l))
			return (NULL);
		k = i;
		while (big[k] == l[j] && l[j] && big[k])
		{
			k++;
			j++;
		}
		if (l[j] == '\0')
			return ((char *)big + i);
		i++;
		len--;
	}
	return (NULL);
}
