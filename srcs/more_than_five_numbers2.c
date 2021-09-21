/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_five_numbers2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 17:15:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_pile_a(t_piles *piles, int i, int *to_move)
{
	while (i < (piles->chunks - 1) && *to_move)
	{
		op_ra(piles);
		*to_move -= 1;
	}
}

void	prepare_a_for_chunk(t_piles *piles, int i)
{
	long	move_up;
	long	move_down;

	if (i != 0 && i != piles->chunks - 1)
	{
		move_up = piles->len_med[i - 1];
		move_down = piles->len_total - piles->len_med[i];
		if (move_up < move_down)
		{
			while (move_up > 0)
			{
				op_ra(piles);
				move_up--;
			}
		}
		else
		{
			while (move_down > 0)
			{
				op_rra(piles);
				move_down--;
			}
		}
	}
}
