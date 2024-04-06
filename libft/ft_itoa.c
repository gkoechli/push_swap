/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:30:33 by gkoechli          #+#    #+#             */
/*   Updated: 2021/12/15 12:32:18 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(size_t n)
{
	int	i;

	i = 1;
	while ((n / 10) > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_fill(long n, int sign, int i, int intlen)
{
	char		*str;
	long int	u;

	u = n;
	if (n < 0)
	{
		u = (n * -1);
		i = 1;
		sign = 1;
	}
	intlen = ft_intlen(u) + i;
	str = malloc(sizeof(char) * intlen + 1);
	if (str == NULL)
		return (NULL);
	str[intlen] = '\0';
	while (intlen > 0)
	{
		str[--intlen] = '0' + u % 10;
		u = u / 10;
	}
	if (sign == 1)
		str[intlen] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		intlen;
	long	imin;

	sign = 0;
	i = 0;
	intlen = 0;
	imin = (long)n;
	return (ft_fill(imin, sign, i, intlen));
}
