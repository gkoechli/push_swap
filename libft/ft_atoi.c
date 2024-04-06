/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:53:56 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 17:44:50 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_translate(const char *str, int i, int sign)
{
	int	tmp;

	tmp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + ((int)str[i] - 48);
		i++;
	}
	if (sign == 1)
		return (tmp * -1);
	return (tmp);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		return (ft_translate(str, i, sign));
	return (0);
}
