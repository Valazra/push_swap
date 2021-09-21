/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 17:15:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a(t_list *pile_a)
{
	if (pile_a)
		printf("%d", pile_a->content);
	else
		printf(" ");
}

void	print_b(t_list *pile_b)
{
	if (pile_b)
		printf("%d", pile_b->content);
}

void	print_numbers(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (!piles)
		ft_error(piles);
	else
	{
		pile_a = piles->a;
		pile_b = piles->b;
		while (pile_a || pile_b)
		{
			print_a(pile_a);
			if (pile_a)
				pile_a = pile_a->next;
			printf("     ");
			print_b(pile_b);
			if (pile_b)
				pile_b = pile_b->next;
			printf ("\n");
		}
	}
}

void	print_piles(t_piles *piles)
{
	if (!piles)
		ft_error(piles);
	if (piles->len_total > 0)
		print_numbers(piles);
}
