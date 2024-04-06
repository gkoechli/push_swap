/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:51:04 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:52:19 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_b_state(t_elem *d)
{
	if (d->b_size == 0)
		return ;
	if (am_i_biggest(d) == YES)
	{
		ft_biggest_on_top(d);
		d->b_max = d->as[0];
		return ;
	}
	if (am_i_smallest(d) == YES)
	{
		ft_biggest_on_top(d);
		d->b_min = d->as[0];
		return ;
	}
	find_next_smaller(d->as[0], d);
}

void	ft_pb_chunks(t_elem *d)
{
	int	i;
	int	stop;

	stop = 0;
	while (stop < d->chunk_size)
	{
		i = 0;
		while (d->as[i] > d->fs[d->chunk_index])
			i++;
		d->min_c = i;
		i = d->a_size - 1;
		while (d->as[i] > d->fs[d->chunk_index])
			i--;
		d->max_c = d->a_size - i ;
		if (d->min_c > d->max_c)
			while (d->max_c-- > 0)
				ft_rra(d);
		else
			while (d->min_c-- > 0)
				ft_ra(d);
		check_b_state(d);
		ft_pb(d);
		stop++;
	}
}

void	ft_last_chunk(t_elem *d)
{
	while (d->b_size < d->stacksize)
	{
		check_b_state(d);
		ft_pb(d);
	}
}

void	split_n_sort(t_elem *d)
{
	while (d->allgood != 1)
	{
		ft_pb_chunks(d);
		d->chunk_index += d->chunk_size;
		if (d->chunk_index >= d->stacksize)
		{
			ft_last_chunk(d);
			d->allgood = 1;
		}
	}
	ft_biggest_on_top(d);
	while (d->b_size > 0)
		ft_pa(d);
}
