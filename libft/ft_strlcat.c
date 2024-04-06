/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:46:14 by gkoechli          #+#    #+#             */
/*   Updated: 2019/11/26 16:30:36 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (dst[i] && i < dstsize)
		++i;
	res = 0;
	while (src[res])
		++res;
	if (dstsize == i)
		return (res + dstsize);
	else
		res += i;
	j = 0;
	while (src[j] && (i + 1) < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
