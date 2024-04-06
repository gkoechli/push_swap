/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficiency.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:22:28 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/17 18:20:23 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_biggest_on_top(t_elem *d)
{
	int	i;

	i = 0;
	while (d->bs[i] != d->b_max)
		i++;
	if (i > d->b_size / 2)
		while (d->bs[0] != d->b_max)
			ft_rrb(d);
	else
		while (d->bs[0] != d->b_max)
			ft_rb(d);
}

void	ft_smallest_on_top(t_elem *d)
{
	int	i;

	i = 0;
	while (d->bs[i] != d->b_min)
		i++;
	if (i > d->b_size / 2)
		while (d->bs[0] != d->b_min)
			ft_rrb(d);
	else
		while (d->bs[0] != d->b_min)
			ft_rb(d);
}

void	exit_fct(t_elem *d, char *errmsg)
{
	if (errmsg)
		write(1, errmsg, ft_strlen(errmsg));
	if (d->tmp != NULL)
		free_tab(d->tmp);
	if (d->as != NULL)
		free(d->as);
	if (d->bs != NULL)
		free(d->bs);
	if (d->fs != NULL)
		free(d->fs);
	exit(EXIT_SUCCESS);
}

void	free_tab(char **tmp)
{
	int	i;

	i = 0;
	if (tmp != NULL)
	{
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
}

int	malloc_stacks(t_elem *d, int i)
{
	d->as = malloc(sizeof(int) * i);
	d->bs = malloc(sizeof(int) * i);
	d->fs = malloc(sizeof(int) * i);
	d->a_size = i;
	d->f_size = i;
	d->stacksize = i;
	if (d->as == NULL || d->bs == NULL || d->fs == NULL)
		return (NO);
	return (YES);
}
