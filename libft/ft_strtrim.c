/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:53:14 by gkoechli          #+#    #+#             */
/*   Updated: 2021/12/15 12:28:33 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_find_start(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (ft_ischarset(s[i], set) == 1)
		i++;
	return (i);
}

static size_t	ft_find_end(const char *s, const char *set)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	while (len > 0 && ft_ischarset(s[len - 1], set) == 1)
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	start = ft_find_start(s1, set);
	len = ft_find_end(s1, set);
	if (len < start)
	{
		s2 = malloc(1);
		if (s2 == NULL)
			return (NULL);
		s2[0] = 0;
		return (s2);
	}
	return (ft_substr(s1, start, (len - start)));
}
