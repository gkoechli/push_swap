/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:43:42 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:50:48 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_case(t_elem *d)
{
	if (d->as[1] > d->as[0] && d->as[1] > d->as[2] && d->as[0] < d->as[2])
		ft_sa(d);
	if (d->as[1] < d->as[0] && d->as[1] > d->as[2])
		ft_sa(d);
	if (d->as[1] > d->as[0] && d->as[1] > d->as[2] && d->as[0] > d->as[2])
		ft_rra(d);
	if (d->as[1] < d->as[0] && d->as[1] < d->as[2] && d->as[0] < d->as[2])
		ft_sa(d);
	if (d->as[1] < d->as[0] && d->as[1] < d->as[2] && d->as[0] > d->as[2])
		ft_ra(d);
	return (0);
}

void	send_smaller(t_elem *d)
{
	while (d->a_size > 3)
	{
		if (d->as[0] != d->big && d->as[0] != d->bigger
			&& d->as[0] != d->biggest)
			ft_pb(d);
		else
			ft_ra(d);
	}
}

void	find_bigger_b(t_elem *d)
{
	int	i;
	int	u;

	i = 1;
	u = 0;
	d->big = d->bs[0];
	while (i < d->b_size)
	{
		if (d->bs[u] < d->bs[i])
		{
			d->big = d->bs[i];
			u = i;
		}
		i++;
	}
	d->big_index = u;
	send_bigger_b(d);
}

void	send_bigger_b(t_elem *d)
{
	int	i;

	i = 0;
	if (d->big_index < (d->b_size / 2 + d->b_size % 2))
	{
		while (d->bs[i] != d->big)
			ft_rb(d);
		ft_pa(d);
	}
	else
	{
		while (d->bs[0] != d->big)
			ft_rrb(d);
		ft_pa(d);
	}
}

void	solve(t_elem *d)
{
	d->b_size = 0;
	find_goal(d);
	if (d->a_size == 2)
	{
		if (d->as[0] > d->as[1])
			ft_sa(d);
		exit_fct(d, NULL);
	}
	if (d->a_size > 20)
		split_n_sort(d);
	else
	{
		find_big_three(d);
		send_smaller(d);
		check_case(d);
		while (d->b_size > 0)
			find_bigger_b(d);
	}
	exit_fct(d, NULL);
}
