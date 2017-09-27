/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:06:44 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/18 19:25:10 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c)
			i++;
	}
	return (count);
}

static int		ft_count_letters(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		words;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * words + 1)))
		return (0);
	while (words--)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_strsub(s, 0, ft_count_letters(s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_count_letters(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
