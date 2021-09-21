/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/18 12:49:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>

typedef struct s_piles
{
	t_list	*a;
	t_list	*b;
	int		len_total;
	int		len_pile_a;
	int		len_pile_b;
	long	min;
	long	max;
	long	chunks;
	long	nbr_op;
	long	*mediane;
	long	*len_med;
}		t_piles;

typedef struct s_min_or_max
{
	int		dir;
	long	pos;
	long	nbr_moves;
}		t_min_or_max;

void	parsing(int ac, char **av, t_piles *piles);
void	ft_error(t_piles *piles);
void	init_piles(t_piles *piles);
int		check_duplicate(t_piles *piles);
void	print_piles(t_piles *piles);
void	op_sa(t_piles *piles);
void	op_sb(t_piles *piles);
void	op_ss(t_piles *piles);
void	op_pa(t_piles *piles);
void	op_pb(t_piles *piles);
void	op_ra(t_piles *piles);
void	op_rb(t_piles *piles);
void	op_rr(t_piles *piles);
void	op_rra(t_piles *piles);
void	op_rrb(t_piles *piles);
void	op_rrr(t_piles *piles);
int		test_sort(t_piles *piles);
void	set_min_max(t_piles *piles);
void	min_first_place(t_piles *piles);
void	two_numbers_sort(t_piles *piles);
void	three_numbers_sort(t_piles *piles);
void	four_numbers_sort(t_piles *piles);
void	five_numbers_sort(t_piles *piles);
void	insert_b(t_piles *piles);
void	more_than_five_numbers_sort(t_piles *piles);
void	set_nbr_chunks(t_piles *piles);
void	find_pos(t_list *pile, long *pos_min, long *pos_max);
void	count_moves(t_min_or_max *min, t_min_or_max *max, int len);
void	prepare_a_for_chunk(t_piles *piles, int i);
void	place_pile_a(t_piles *piles, int i, int *remaining);
void	free_piles(t_piles *piles);
void	free_list(t_list *pile);

#endif
