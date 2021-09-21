/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 12:43:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ss(t_piles *piles)
{
	write(1, "ss\n", 3);
	op_sa(piles);
	op_sb(piles);
	piles->nbr_op--;
}

void	op_rr(t_piles *piles)
{
	write(1, "rr\n", 3);
	op_ra(piles);
	op_rb(piles);
	piles->nbr_op--;
}

void	op_rrr(t_piles *piles)
{
	write(1, "rrr\n", 3);
	op_rra(piles);
	op_rrb(piles);
	piles->nbr_op--;
}
