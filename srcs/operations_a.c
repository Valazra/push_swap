/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 15:10:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_piles *piles)
{
	t_list	*pile_a;
	long	tmp;

	write(1, "sa\n", 3);
	if (!piles)
		ft_error(piles);
	pile_a = piles->a;
	if (!pile_a)
		ft_error(piles);
	if (pile_a->next)
	{
		tmp = pile_a->content;
		pile_a->content = pile_a->next->content;
		pile_a->next->content = tmp;
	}
	piles->nbr_op++;
}

void	op_pa(t_piles *piles)
{
	t_list	*pile_b1;
	t_list	*pile_b2;
	t_list	*new;
	long	tmp;

	write(1, "pa\n", 3);
	if (!piles)
		ft_error(piles);
	pile_b1 = piles->b;
	if (!pile_b1)
		ft_error(piles);
	pile_b2 = piles->b->next;
	tmp = pile_b1->content;
	new = ft_lstnew(tmp);
	ft_lstadd_front(&piles->a, new);
	piles->b = pile_b2;
	free_list(pile_b1);
	piles->len_pile_a++;
	piles->len_pile_b--;
	piles->nbr_op++;
}

void	op_ra(t_piles *piles)
{
	t_list	*pile_a1;
	t_list	*pile_a2;
	t_list	*new;
	long	tmp;

	write(1, "ra\n", 3);
	if (!piles)
		ft_error(piles);
	if (!piles->a)
		ft_error(piles);
	pile_a1 = piles->a;
	if (!pile_a1)
		ft_error(piles);
	tmp = pile_a1->content;
	new = ft_lstnew(tmp);
	pile_a2 = pile_a1->next;
	if (!pile_a2)
		ft_error(piles);
	ft_lstadd_back(&piles->a, new);
	piles->a = pile_a2;
	free_list(pile_a1);
	piles->nbr_op++;
}

void	op_rra(t_piles *piles)
{
	t_list	*pile_a1;
	t_list	*pile_a2;
	t_list	*new;
	long	tmp;

	write(1, "rra\n", 4);
	if (!piles)
		ft_error(piles);
	if (!piles->a)
		ft_error(piles);
	pile_a1 = piles->a;
	if (!pile_a1)
		ft_error(piles);
	while (pile_a1->next->next != NULL)
		pile_a1 = pile_a1->next;
	pile_a2 = pile_a1->next;
	tmp = pile_a2->content;
	new = ft_lstnew(tmp);
	ft_lstadd_front(&piles->a, new);
	pile_a1->next = NULL;
	free_list(pile_a2);
	piles->nbr_op++;
}
