/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:37:01 by gkoechli          #+#    #+#             */
/*   Updated: 2019/11/29 16:35:39 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;

	if (!lst)
		return (0);
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
	{
		ft_lstclear(&tmp, del);
		return (0);
	}
	lst = lst->next;
	new = tmp;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
