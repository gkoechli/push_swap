/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:28:45 by gkoechli          #+#    #+#             */
/*   Updated: 2021/12/15 12:44:29 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (0);
	while (len-- > 0)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
