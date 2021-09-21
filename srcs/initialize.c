/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/18 12:49:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_piles(t_piles *piles)
{
	piles->a = 0;
	piles->b = 0;
	piles->len_total = 0;
	piles->len_pile_a = 0;
	piles->len_pile_b = 0;
	piles->chunks = 0;
	piles->nbr_op = 0;
	piles->mediane = 0;
	piles->len_med = 0;
}

void	set_min_max(t_piles *piles)
{
	t_list	*pile_a;

	if (!piles)
		ft_error(piles);
	pile_a = piles->a;
	piles->min = piles->a->content;
	piles->max = piles->a->content;
	while (pile_a)
	{
		if (pile_a->content > piles->max)
			piles->max = pile_a->content;
		if (pile_a->content < piles->min)
			piles->min = pile_a->content;
		pile_a = pile_a->next;
	}
	if (pile_a)
	{
		free(pile_a);
		pile_a = NULL;
	}
}
