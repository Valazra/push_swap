/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less_sort2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/08 13:10:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_b(t_piles *piles)
{
	long	last_nbr;

	last_nbr = piles->a->next->next->content;
	while (piles->len_pile_b)
	{
		if (piles->len_pile_b == 2)
		{
			if (piles->b->next->content < piles->a->content)
			{
				op_sb(piles);
				op_pa(piles);
			}
		}
		if (piles->b->content < piles->a->content)
			op_pa(piles);
		if (piles->len_pile_b)
		{
			if (piles->a->content == last_nbr)
			{
				op_ra(piles);
				break ;
			}
			op_ra(piles);
		}
	}
}
