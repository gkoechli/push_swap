/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoechli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:15:32 by gkoechli          #+#    #+#             */
/*   Updated: 2022/01/18 11:29:15 by gkoechli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# define YES 0
# define NO 1

typedef struct s_elem
{
	char	**tmp;
	char	*s;
	int		*as;
	int		*bs;
	int		*fs;
	int		u;
	int		n;
	int		stacksize;
	int		biggest;
	int		modul;
	int		bigger;
	int		big;
	int		rmin;
	int		rmax;
	int		smaller;
	int		max;
	int		b_max;
	int		middle;
	int		min;
	int		chunk_index;
	int		chunk_size;
	int		allgood;
	int		b_min;
	int		min_c;
	int		min_rc;
	int		max_c;
	int		max_rc;
	int		min_b;
	int		min_b_index;
	int		min_index;
	int		big_index;
	int		five_min;
	int		five_min_bis;	
	int		a_size;
	int		b_size;
	int		f_size;
	int		last_move;
}	t_elem;

int		malloc_stacks(t_elem *d, int i);
int		check_wrong_char(char *tmp);
void	free_tab(char **tmp);
int		check_no(char **av);
void	ft_build(int ac, char **av, t_elem *d);
void	ft_build_str(char *s, t_elem *d);
int		check_errors_str(char *s);
int		check_no_str(char *s);
int		check_str_valid(char *str);
void	find_next_smaller(int x, t_elem *d);
void	ft_biggest_on_top(t_elem *d);
void	ft_smallest_on_top(t_elem *d);
int		am_i_biggest(t_elem *d);	
int		am_i_smallest(t_elem *d);	
void	ft_pb_chunks(t_elem *d);
void	ft_pb_second_half(t_elem *d);
void	find_big_n_small(t_elem *d);
void	compare_move_nb(t_elem *d);
void	ft_push_smallest(t_elem *d);
void	ft_sort_b(t_elem *d);
void	pa_closest(t_elem *d);
void	split_n_sort(t_elem *d);
void	check_already_ok(t_elem *d);
int		ft_find_next(int x, t_elem *d);
void	find_b_max(t_elem *d);
int		search_bigger_b(int x, t_elem *d);
int		search_next_big(int x, t_elem *d);
int		search_next_small(int x, t_elem *d);
int		is_there_bigger(int x, t_elem *d);
void	chunk_m_split(t_elem *d);
void	send_bigger_b(t_elem *d);
int		check_f(t_elem *d);
void	small_first(t_elem *d);
void	find_goal(t_elem *d);
void	dump_b_to_f(t_elem *d);
void	find_middle(t_elem *d);
void	find_the_big_one(t_elem *d);
void	find_biggest(t_elem *d);
void	find_big(t_elem *d);
void	find_bigger(t_elem *d);
void	find_big_three(t_elem *d);
void	send_bigger_b(t_elem *d);
int		check_double(t_elem *d);
void	exit_fct(t_elem *d, char *errmsg);
void	send_min(t_elem *d);
int		check_case(t_elem *d);
void	solve(t_elem *d);
void	send_smaller(t_elem *d);
void	find_bigger_b(t_elem *d);
void	find_small(t_elem *d);
int		ft_sa(t_elem *d);
int		ft_sb(t_elem *d);
int		ft_ss(t_elem *d);
int		ft_pa(t_elem *d);
int		ft_pb(t_elem *d);
int		ft_ra(t_elem *d);
int		ft_rb(t_elem *d);
int		ft_rr(t_elem *d);
int		ft_rra(t_elem *d);
int		ft_rrb(t_elem *d);
int		ft_rrr(t_elem *d);
void	ft_printf(t_elem *d);
void	ft_printf_f(t_elem *d);
#endif
