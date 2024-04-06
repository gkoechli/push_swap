/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:08:03 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:23:06 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sb(t_elem *d)
{
	int	i;

	if (d->b_size < 2)
		return (0);
	i = d->bs[0];
	d->bs[0] = d->bs[1];
	d->bs[1] = i;
	write(1, "sb\n", 3);
	return (0);
}

int	ft_rrb(t_elem *d)
{
	int	i;
	int	u;

	if (d->b_size < 2)
		return (0);
	u = 0;
	i = d->b_size - 1;
	u = d->bs[d->b_size - 1];
	while (i > 0)
	{
		d->bs[i] = d->bs[i - 1];
		i--;
	}
	d->bs[0] = u;
	write(1, "rrb\n", 4);
	return (0);
}

int	ft_rb(t_elem *d)
{
	int	u;
	int	i;

	i = 0;
	u = 0;
	u = d->bs[0];
	while (i < d->b_size - 1)
	{
		d->bs[i] = d->bs[i + 1];
		i++;
	}
	d->bs[i] = u;
	write(1, "rb\n", 3);
	return (0);
}

int	ft_pb(t_elem *d)
{
	int	i;
	int	j;

	if (d->a_size < 1)
		return (0);
	j = d->b_size;
	i = d->as[0];
	while (j > 0)
	{
		d->bs[j] = d->bs[j - 1];
		j--;
	}
	d->bs[0] = i;
	d->b_size += 1;
	i = 0;
	while (i < d->a_size - 1)
	{
		d->as[i] = d->as[i + 1];
		i++;
	}
	d->a_size -= 1;
	find_b_max(d);
	write(1, "pb\n", 3);
	return (0);
}
