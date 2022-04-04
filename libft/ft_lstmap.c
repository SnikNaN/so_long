/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:28:57 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 02:28:57 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	if (new_list)
	{
		while (lst)
		{
			tmp = ft_lstnew((*f)(lst->content));
			if (!tmp)
			{
				ft_lstclear(&new_list, *del);
				return (NULL);
			}
			ft_lstadd_back(&new_list, tmp);
			lst = lst->next;
		}
	}
	return (new_list);
}
