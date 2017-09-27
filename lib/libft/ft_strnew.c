/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:45:19 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/16 16:19:17 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!(newstr = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	while (i <= size)
	{
		newstr[i] = 0;
		i++;
	}
	return (newstr);
}
