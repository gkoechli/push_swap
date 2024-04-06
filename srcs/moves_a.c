/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:06:24 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:58:44 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rra(t_elem *d)
{
	int	i;
	int	u;

	if (d->a_size < 2)
		return (0);
	u = 0;
	i = d->a_size - 1;
	u = d->as[d->a_size - 1];
	while (i > 0)
	{
		d->as[i] = d->as[i - 1];
		i--;
	}
	d->as[0] = u;
	write(1, "rra\n", 4);
	return (0);
}

int	ft_ra(t_elem *d)
{
	int	u;
	int	i;

	i = 0;
	u = 0;
	u = d->as[0];
	while (i < d->a_size - 1)
	{
		d->as[i] = d->as[i + 1];
		i++;
	}
	d->as[i] = u;
	write(1, "ra\n", 3);
	return (0);
}

int	ft_pa(t_elem *d)
{
	int	i;
	int	j;

	if (d->b_size < 1)
		return (0);
	j = d->a_size;
	i = d->bs[0];
	while (j > 0)
	{
		d->as[j] = d->as[j - 1];
		j--;
	}
	d->as[0] = i;
	d->a_size += 1;
	i = 0;
	while (i < d->b_size - 1)
	{
		d->bs[i] = d->bs[i + 1];
		i++;
	}
	d->b_size -= 1;
	write(1, "pa\n", 3);
	return (0);
}

int	ft_sa(t_elem *d)
{
	int	i;

	if (d->a_size < 2)
		return (0);
	i = d->as[0];
	d->as[0] = d->as[1];
	d->as[1] = i;
	write(1, "sa\n", 3);
	return (0);
}

int	check_wrong_char(char *str)
{
	if (!str)
		return (NO);
	if (str[0] == '\0')
		return (NO);
	if (ft_strlen(str) == 0)
		return (NO);
	return (YES);
}
