/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:45:28 by gkoechli          #+#    #+#             */
/*   Updated: 2021/12/15 12:24:55 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	pop;

	pop = len + 1;
	i = 0;
	j = 0;
	if (!*needle || needle == haystack)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] && len-- > 0)
	{
		while (haystack[(i + j)] == needle[j])
		{
			j++;
			if (j == ft_strlen(needle) && (i + j) < pop)
				return ((char *)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
