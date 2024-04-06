/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:32:35 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:52:07 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_ss(t_elem *d)
{
	int	i;

	i = 0;
	if (d->a_size > 1)
	{
		i = d->as[1];
		d->as[0] = d->as[1];
		d->as[1] = i;
	}
	if (d->b_size < 2)
		return (0);
	i = d->bs[0];
	d->bs[0] = d->bs[1];
	d->bs[1] = i;
	write(1, "ss\n", 3);
	return (0);
}

int	ft_rr(t_elem *d)
{
	int	u;
	int	i;

	i = 0;
	u = d->as[0];
	while (i < d->a_size - 1)
	{
		d->as[i] = d->as[i + 1];
		i++;
	}
	d->as[i] = u;
	u = d->bs[0];
	while (i < d->b_size - 1)
	{
		d->bs[i] = d->bs[i + 1];
		i++;
	}
	d->bs[i] = u;
	write(1, "rr\n", 3);
	return (0);
}

int	ft_rrr(t_elem *d)
{
	int	i;
	int	u;

	if (d->a_size < 2 || d->b_size < 2)
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
	i = d->b_size - 1;
	u = d->bs[d->b_size - 1];
	while (i > 0)
	{
		d->bs[i] = d->bs[i - 1];
		i--;
	}
	d->bs[0] = u;
	write(1, "rrr\n", 4);
	return (0);
}

int	check_f(t_elem *d)
{
	int	i;

	i = 0;
	while (i < d->f_size - 1)
	{
		if (d->fs[i] < d->fs[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	find_goal(t_elem *d)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (check_f(d) != 0)
	{
		while (i < d->stacksize - 1)
		{
			if (d->fs[i] > d->fs[i + 1])
			{
				y = d->fs[i];
				d->fs[i] = d->fs[i + 1];
				d->fs[i + 1] = y;
			}
			i++;
		}
		i = 0;
	}
	d->min = d->fs[0];
	d->middle = d->fs[d->stacksize / 2];
	d->chunk_size = d->stacksize / 10;
	d->modul = d->stacksize % 10;
	d->chunk_index = d->chunk_size - 1;
}
