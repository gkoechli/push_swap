/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:16:22 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/18 11:29:37 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_no_str(char *str)
{
	int		i;
	int		y;
	char	**tmp;
	int		check;

	i = 0;
	y = 0;
	check = 0;
	tmp = NULL;
	tmp = ft_split(str, ' ');
	while (tmp[i])
	{
		while (tmp[i] && tmp[i][y] != '\0')
		{
			if (tmp[i][y] < '0' || tmp[i][y] > '9')
				if (tmp[i][y] != '-')
					check = 1;
			y++;
		}
		y = 0;
		i++;
	}
	if (tmp != NULL)
		free_tab(tmp);
	return (check);
}

int	check_errors_str(char *str)
{
	int		i;
	int		y;
	char	**tmp;
	int		match;

	tmp = NULL;
	i = 0;
	match = 0;
	y = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i])
	{
		while (y < i)
		{
			if (tmp[y] == tmp[i])
				match = 1;
			y++;
		}
		y = 0;
		i++;
	}
	if (tmp != NULL)
		free_tab(tmp);
	return (match);
}

int	check_no(char **av)
{
	int	i;
	int	y;	

	i = 1;
	y = 0;
	while (av[i])
	{
		while (av[i][y] != '\0')
		{
			if (av[i][y] < '0' || av[i][y] > '9')
				if (av[i][y] != '-')
					return (1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

void	ft_build(int ac, char **av, t_elem *d)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	if (malloc_stacks(d, ac -1) == NO)
		exit_fct(d, "Error\n");
	while (i < ac - 1)
	{
		y = ft_atoi(av[i + 1]);
		d->s = ft_itoa(y);
		if (ft_strcmp(d->s, av[i + 1]) != 0)
		{
			if (d->s != NULL)
				free(d->s);
			exit_fct(d, "Error\n");
		}
		else
			free(d->s);
		d->as[i] = y;
		d->fs[i] = d->as[i];
		i++;
	}
}

void	ft_build_str(char *str, t_elem *d)
{
	d->n = 0;
	d->tmp = ft_split(str, ' ');
	while (d->tmp[d->n])
		d->n++;
	if (malloc_stacks(d, d->n) == NO)
		exit_fct(d, "Error\n");
	d->n = -1;
	while (d->tmp[++d->n])
	{
		if (check_wrong_char(d->tmp[d->n]) == NO)
			exit_fct(d, "Error\n");
		d->u = ft_atoi(d->tmp[d->n]);
		d->s = ft_itoa(d->u);
		if (ft_strcmp(d->s, d->tmp[d->n]) != 0)
		{
			if (d->s != NULL)
				free(d->s);
			exit_fct(d, "Error\n");
		}
		else
			free(d->s);
		d->as[d->n] = ft_atoi(d->tmp[d->n]);
		d->fs[d->n] = d->as[d->n];
	}
}
