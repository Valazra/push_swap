/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 15:02:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_piles *piles)
{
	t_list	*l1;
	t_list	*l2;

	l1 = piles->a;
	while (l1->next != NULL)
	{
		l2 = l1;
		while (l2->next != NULL)
		{
			l2 = l2->next;
			if (l1->content == l2->content)
				return (1);
		}
		l1 = l1->next;
	}
	return (0);
}

void	ft_error(t_piles *piles)
{
	write(2, "Error\n", 6);
	free_piles(piles);
	exit(0);
}
