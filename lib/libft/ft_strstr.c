/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:36:34 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/18 12:59:30 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (l[0] == '\0')
		return (char *)(big);
	while (big[i])
	{
		while (big[i + j] == l[j])
		{
			if (l[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
