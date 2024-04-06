/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:28:31 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:43:08 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_big_three(t_elem *d)
{
	int	i;

	i = 0;
	d->biggest = d->as[i];
	while (i < d->a_size - 1)
	{
		if (d->biggest < d->as[i + 1])
			d->biggest = d->as[i + 1];
		i++;
	}
	find_bigger(d);
}

void	find_bigger(t_elem *d)
{
	int	i;

	i = 0;
	if (d->as[i] == d->biggest)
		i++;
	d->bigger = d->as[i];
	while (i < d->a_size - 1)
	{
		if (d->bigger < d->as[i + 1] && d->as[i + 1] != d->biggest)
			d->bigger = d->as[i + 1];
		i++;
	}
	find_big(d);
}

void	find_big(t_elem *d)
{
	int	i;

	i = 0;
	while (d->as[i] == d->biggest || d->as[i] == d->bigger)
		i++;
	d->big = d->as[i];
	while (i < d->a_size - 1)
	{
		if (d->big < d->as[i + 1] && (d->as[i + 1] != d->biggest)
			&& d->as[i + 1] != d->bigger)
			d->big = d->as[i + 1];
		i++;
	}
}

void	find_b_max(t_elem *d)
{
	int	i;

	i = 0;
	d->b_max = d->bs[0];
	while (i < d->b_size)
	{
		if (d->b_max < d->bs[i])
			d->b_max = d->bs[i];
		i++;
	}
}

int	check_double(t_elem *d)
{
	int	i;
	int	y;

	i = 0;
	y = d->a_size - 1;
	while (y > 0)
	{
		while (i < y)
		{
			if (d->as[y] == d->as[i])
				exit_fct(d, "Error\n");
			i++;
		}	
		y--;
		i = 0;
	}		
	return (0);
}
