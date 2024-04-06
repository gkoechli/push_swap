/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:32:16 by gkoechli          #+#    #+#             */
/*   Updated: 2019/11/28 15:43:01 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst != NULL)
	{
		del(tmp->content);
		(*lst) = (*lst)->next;
		free(tmp);
		tmp = *lst;
	}
}
