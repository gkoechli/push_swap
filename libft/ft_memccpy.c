/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:05:44 by gkoechli          #+#    #+#             */
/*   Updated: 2021/12/29 15:47:04 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- > 0)
	{
		d[i] = s[i];
		i++;
		if (s[i - 1] == (unsigned char)c)
			return (dst);
	}
	return (0);
}
