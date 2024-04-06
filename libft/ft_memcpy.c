/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:53:53 by gkoechli          #+#    #+#             */
/*   Updated: 2019/11/24 19:03:21 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dst == src)
		return (0);
	d = dst;
	s = src;
	if (d == 0 && s == 0)
		return (dst);
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
