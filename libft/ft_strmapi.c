/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:14:15 by gkoechli          #+#    #+#             */
/*   Updated: 2021/12/15 12:25:53 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*str;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[i] = f(i, s[i]);
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
