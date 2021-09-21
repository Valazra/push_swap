/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 15:22:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *pile)
{
	if (pile)
	{
		free(pile);
		pile = NULL;
	}
}

void	free_piles2(t_piles *piles, t_list *tmp)
{
	if (piles->a)
	{
		tmp = piles->a->next;
		while (tmp != NULL)
		{
			free(piles->a);
			piles->a = tmp;
			tmp = piles->a->next;
		}
		free(piles->a);
		piles->a = NULL;
	}
	if (piles->b)
	{
		tmp = piles->b->next;
		while (tmp != NULL)
		{
			free(piles->b);
			piles->b = tmp;
			tmp = piles->b->next;
		}
	}
}

void	free_piles(t_piles *piles)
{
	t_list	*tmp;

	tmp = 0;
	free_piles2(piles, tmp);
	if (piles->mediane)
	{
		free(piles->mediane);
		piles->mediane = 0;
	}
	if (piles->len_med)
	{
		free(piles->len_med);
		piles->len_med = 0;
	}
}
