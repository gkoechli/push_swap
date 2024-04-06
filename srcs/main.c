/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:56:48 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/18 11:18:46 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
void	ft_printf(t_elem *d)
{
	int	i;

	i = 0;
	printf("//// A ////////// STACKS /////////// B /////\n\n");	
	while (i < d->a_size || i < d->b_size)
	{	
		if (i < d->a_size)
			printf("%d:    %d", i + 1, d->as[i]);
		else	
			printf("      ");
		printf("                               ");
		if (i < d->b_size)
			printf("%d:%d", i + 1, d->bs[i]);
		i++;
		printf("\n");
	}
	printf("\n");
}
*/

void	check_already_ok(t_elem *d)
{
	int	i;

	i = 0;
	d->allgood = 0;
	while (i < d->a_size - 1)
	{
		if (d->as[i] > d->as[i + 1])
			return ;
		i++;
	}
	d->allgood = 1;
	exit_fct(d, NULL);
}

int	check_str_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NO);
	if (str[0] == '\0')
		return (NO);
	while (str[i])
	{
		if (str[i] < 0 && str[i] > 9)
		{
			if (ft_strlen(str) < 2)
				return (NO);
			if (str[i] != '-')
				return (NO);
		}
		i++;
	}
	return (YES);
}

int	check_empty_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) < 1)
			return (YES);
		i++;
	}
	return (NO);
}

void	error_build_str(char **av, t_elem *d)
{
	if (check_str_valid(av[1]) == NO)
		exit_fct(d, "Error\n");
	if (check_no_str(av[1]) == 1 && check_errors_str(av[1]) == 1)
		exit_fct(d, "Error\n");
	if (ft_strlen(av[1]) < 1)
		exit_fct(d, "Error\n");
	ft_build_str(av[1], d);
}

int	main(int ac, char **av)
{
	t_elem	d;

	ft_bzero(&d, sizeof(d));
	if (ac < 2)
		return (0);
	if (ac == 2)
		error_build_str(av, &d);
	else
	{
		if (check_empty_arg(ac, av) == YES)
			exit_fct(&d, "Error\n");
		if (check_no(av) == 1)
			exit_fct(&d, "Error\n");
		ft_build(ac, av, &d);
	}
	check_double(&d);
	check_already_ok(&d);
	if (d.stacksize == 3)
	{
		check_case(&d);
		exit_fct(&d, NULL);
	}
	solve(&d);
	exit_fct(&d, NULL);
	return (0);
}
