/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:57:58 by mbarreto          #+#    #+#             */
/*   Updated: 2021/11/24 18:58:00 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*e;

	e = ft_lstnew(f(lst->content));
	if (!e)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	l = e;
	lst = lst->next;
	while (lst)
	{
		e = ft_lstnew(f(lst->content));
		if (!e)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&l, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&l, e);
	}
	return (l);
}
