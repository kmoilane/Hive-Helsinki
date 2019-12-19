/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:57:42 by kmoilane          #+#    #+#             */
/*   Updated: 2019/11/04 13:32:42 by kmoilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates a list 'lst' and applies the function 'f' to each link to create
** a "fresh" list (using malloc(3)) resulting from the successive applications
** of 'f'. If the allocation fails, the function return NULL.
*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*fresh;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	temp = (f)(lst);
	if (!(fresh = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	result = fresh;
	while (lst->next)
	{
		temp = (f)(lst->next);
		if (!(fresh->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		lst = lst->next;
		fresh = fresh->next;
	}
	return (result);
}
