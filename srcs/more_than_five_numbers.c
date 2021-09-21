/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_five_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 16:54:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_a2(t_piles *piles, t_min_or_max the_chosen_one)
{
	while (the_chosen_one.nbr_moves > 0)
	{
		if (!the_chosen_one.dir)
			op_rb(piles);
		else
		{
			if (piles->len_pile_b != 1 && piles->len_pile_b != 0)
				op_rrb(piles);
		}
		the_chosen_one.nbr_moves--;
	}
}

void	chunk_to_a(t_piles *piles, int *to_move)
{
	t_min_or_max	min;
	t_min_or_max	max;
	t_min_or_max	the_chosen_one;

	while (piles->b)
	{
		find_pos(piles->b, &min.pos, &max.pos);
		count_moves(&min, &max, piles->len_pile_b);
		the_chosen_one = max;
		if (min.nbr_moves < max.nbr_moves)
			the_chosen_one = min;
		else
			*to_move += 1;
		chunk_to_a2(piles, the_chosen_one);
		op_pa(piles);
		if (the_chosen_one.pos != max.pos && piles->len_pile_a > 1)
			op_ra(piles);
	}
}

void	chunk_to_b(t_piles *piles, long count, int i)
{
	if (i == 0)
		piles->len_med[i] = 0;
	else
		piles->len_med[i] = piles->len_med[i - 1];
	while (count)
	{
		if (piles->a->content <= piles->mediane[i])
		{
			op_pb(piles);
			piles->len_med[i]++;
		}
		else
			op_ra(piles);
		count--;
	}
}

void	more_than_five_numbers_sort(t_piles *piles)
{
	int	i;
	int	count;
	int	to_move;

	i = 0;
	count = piles->len_total;
	set_nbr_chunks(piles);
	while (i < piles->chunks)
	{
		to_move = 0;
		chunk_to_b(piles, count, i);
		prepare_a_for_chunk(piles, i);
		chunk_to_a(piles, &to_move);
		place_pile_a(piles, i, &to_move);
		count = piles->len_total - piles->len_med[i];
		i++;
	}
	min_first_place(piles);
}
