/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:37:34 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/21 14:36:41 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	void	*tmp;

	while (*alst != NULL)
	{
		tmp = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = tmp;
	}
	*alst = NULL;
}
