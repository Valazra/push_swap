/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 15:13:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb(t_piles *piles)
{
	t_list	*pile_b;
	long	tmp;

	write(1, "sb\n", 3);
	if (!piles)
		ft_error(piles);
	pile_b = piles->b;
	if (!pile_b)
		ft_error(piles);
	if (pile_b->next)
	{
		tmp = pile_b->content;
		pile_b->content = pile_b->next->content;
		pile_b->next->content = tmp;
	}
	piles->nbr_op++;
}

void	op_pb(t_piles *piles)
{
	t_list	*pile_a1;
	t_list	*pile_a2;
	t_list	*new;
	long	tmp;

	write(1, "pb\n", 3);
	if (!piles)
		ft_error(piles);
	pile_a1 = piles->a;
	if (!pile_a1)
		ft_error(piles);
	pile_a2 = piles->a->next;
	tmp = pile_a1->content;
	new = ft_lstnew(tmp);
	ft_lstadd_front(&piles->b, new);
	piles->a = pile_a2;
	free_list(pile_a1);
	piles->len_pile_b++;
	piles->len_pile_a--;
	piles->nbr_op++;
}

void	op_rb(t_piles *piles)
{
	t_list	*pile_b1;
	t_list	*pile_b2;
	t_list	*new;
	long	tmp;

	write(1, "rb\n", 3);
	if (!piles)
		ft_error(piles);
	if (!piles->b)
		ft_error(piles);
	pile_b1 = piles->b;
	if (!pile_b1)
		ft_error(piles);
	tmp = pile_b1->content;
	new = ft_lstnew(tmp);
	pile_b2 = pile_b1->next;
	if (!pile_b2)
		ft_error(piles);
	ft_lstadd_back(&piles->b, new);
	piles->b = pile_b2;
	free_list(pile_b1);
	piles->nbr_op++;
}

void	op_rrb(t_piles *piles)
{
	t_list	*pile_b1;
	t_list	*pile_b2;
	t_list	*new;
	long	tmp;

	write(1, "rrb\n", 4);
	if (!piles)
		ft_error(piles);
	if (!piles->b)
		ft_error(piles);
	pile_b1 = piles->b;
	if (!pile_b1)
		ft_error(piles);
	while (pile_b1->next->next != NULL)
		pile_b1 = pile_b1->next;
	pile_b2 = pile_b1->next;
	tmp = pile_b2->content;
	new = ft_lstnew(tmp);
	ft_lstadd_front(&piles->b, new);
	pile_b1->next = NULL;
	free_list(pile_b2);
	piles->nbr_op++;
}
