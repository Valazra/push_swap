/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/19 17:06:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers_sort(t_piles *piles)
{
	t_list	*pile_a;

	if (!piles)
		ft_error(piles);
	pile_a = piles->a;
	if (pile_a->content > pile_a->next->content)
		op_sa(piles);
}

void	three_numbers_sort2(t_piles *piles, int n1, int n2, int n3)
{
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		op_sa(piles);
		op_ra(piles);
	}
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		op_sa(piles);
		op_rra(piles);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		op_ra(piles);
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		op_sa(piles);
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		op_rra(piles);
}

void	three_numbers_sort(t_piles *piles)
{
	t_list	*pile_a;
	int		n1;
	int		n2;
	int		n3;

	if (!piles)
		ft_error(piles);
	pile_a = piles->a;
	n1 = piles->a->content;
	n2 = piles->a->next->content;
	n3 = piles->a->next->next->content;
	three_numbers_sort2(piles, n1, n2, n3);
}

void	four_numbers_sort(t_piles *piles)
{
	if (!piles)
		ft_error(piles);
	op_pb(piles);
	three_numbers_sort(piles);
	op_pa(piles);
	if (piles->a->content == piles->min)
		return ;
	else if (piles->a->content == piles->max)
		op_ra(piles);
	else if (piles->a->content > piles->a->next->content
		&& piles->a->content > piles->a->next->next->content)
	{
		op_rra(piles);
		op_sa(piles);
		op_ra(piles);
		op_ra(piles);
	}
	else if (piles->a->content > piles->a->next->content
		&& piles->a->content < piles->a->next->next->content)
		op_sa(piles);
}

void	five_numbers_sort(t_piles *piles)
{
	op_pb(piles);
	op_pb(piles);
	three_numbers_sort(piles);
	insert_b(piles);
	if (piles->len_pile_b)
	{
		op_pa(piles);
		if (piles->len_pile_b)
		{
			if (piles->b->content < piles->a->content)
				op_pa(piles);
			else
			{
				op_ra(piles);
				op_pa(piles);
			}
		}
	}
	min_first_place(piles);
}
