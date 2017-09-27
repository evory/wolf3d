/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:30:57 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/18 16:51:52 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (0);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (s[i + 1] == '\0')
			return (ft_strdup(""));
		i++;
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (ft_strsub(s, i, (j - i + 1)));
}
