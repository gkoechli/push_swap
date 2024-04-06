/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:22:07 by gkoechli          #+#    #+#             */
/*   Updated: 2019/11/28 15:42:11 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!(alst || new))
		return ;
	tmp = *alst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
	{
		tmp = new;
		*alst = new;
	}
}
