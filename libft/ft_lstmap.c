/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:50:36 by jcrisp            #+#    #+#             */
/*   Updated: 2018/10/21 16:59:50 by jcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *lastnode;
	t_list *currentnode;

	if (lst && f)
	{
		head = f(lst);
		if (!head)
			return (NULL);
		lst = lst->next;
		lastnode = head;
		while (lst)
		{
			currentnode = f(lst);
			if (!currentnode)
				return (NULL);
			lastnode->next = currentnode;
			lastnode = currentnode;
			lst = lst->next;
		}
		return (head);
	}
	return (NULL);
}
