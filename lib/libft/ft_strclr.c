/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:03:18 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/18 16:48:15 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			s[i] = '\0';
			i++;
		}
	}
}
