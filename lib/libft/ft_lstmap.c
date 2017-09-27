/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:05:44 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/22 12:41:53 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	new_list = NULL;
	if (lst && f)
	{
		new_list = (*f)(lst);
		if (new_list && lst->next)
			new_list->next = ft_lstmap(lst->next, f);
	}
	return (new_list);
}
