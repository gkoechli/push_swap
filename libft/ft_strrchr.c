/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:33:01 by gkoechli          #+#    #+#             */
/*   Updated: 2021/12/15 12:30:29 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (c == '\0')
	{
		while (str[i])
			i++;
		return ((char *)&str[i]);
	}
	while (str[i])
	{
		if (str[i] == c)
			check++;
		i++;
	}
	if (check == 0)
		return (0);
	while (i > 0 && str[i] != c)
		i--;
	return ((char *)&str[i]);
}
