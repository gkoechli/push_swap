/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:22:47 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:22:34 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	am_i_biggest(t_elem *d)
{
	int	i;

	i = 0;
	while (i < d->b_size)
	{
		if (d->bs[i] > d->as[0])
			return (NO);
		i++;
	}
	return (YES);
}

void	find_biggest_b(t_elem *d)
{
	int	i;

	i = 1;
	d->b_max = d->bs[0];
	if (d->b_size == 1)
		return ;
	while (i < d->b_size)
	{
		if (d->b_max < d->bs[i])
			d->b_max = d->bs[i];
		i++;
	}
}

void	find_smallest_b(t_elem *d)
{
	int	i;

	i = 1;
	d->b_min = d->bs[0];
	if (d->b_size == 1)
		return ;
	while (i < d->b_size)
	{
		if (d->b_min > d->bs[i])
			d->b_min = d->bs[i];
		i++;
	}
}

void	find_next_smaller(int x, t_elem *d)
{
	int	j;
	int	i;
	int	u;

	j = 0;
	u = 0;
	i = d->b_size - 1;
	while (d->bs[i--] < x)
		j++;
	i = 0;
	if (j == 0)
	{	
		while (d->bs[0] > x)
			ft_rb(d);
		return ;
	}
	while (d->bs[i++] > x)
		u++;
	if (j > u && u != 0)
		while (u-- > 0)
			ft_rb(d);
	else
		while (j-- > 0)
			ft_rrb(d);
}

int	am_i_smallest(t_elem *d)
{
	int	i;

	i = 0;
	while (i < d->b_size)
	{
		if (d->bs[i] < d->as[0])
			return (NO);
		i++;
	}
	return (YES);
}
