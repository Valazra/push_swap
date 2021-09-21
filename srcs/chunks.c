/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 15:18:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_median(t_piles *piles, int count, long min)
{
	t_list	*list;
	long	next_min;
	long	nb;
	int		i;

	i = 0;
	while (i < count - 1)
	{
		next_min = piles->max;
		list = piles->a;
		while (list)
		{
			nb = list->content;
			if (nb > min && nb < next_min)
				next_min = nb;
			list = list->next;
		}
		min = next_min;
		i++;
	}
	return (min);
}

void	malloc_med(t_piles *piles)
{
	piles->mediane = malloc(sizeof(long) * piles->chunks);
	if (!piles->mediane)
		ft_error(piles);
	piles->len_med = malloc(sizeof(long) * piles->chunks);
	if (!piles->len_med)
		ft_error(piles);
}

void	set_nbr_chunks(t_piles *piles)
{
	long	count;
	long	mod;
	long	min;
	int		i;

	piles->chunks = piles->len_total / 80;
	mod = piles->len_total % 80;
	if (mod)
		piles->chunks++;
	malloc_med(piles);
	piles->mediane[piles->chunks - 1] = piles->max;
	min = piles->min;
	i = 0;
	while (i < piles->chunks - 1)
	{
		count = piles->len_total / piles->chunks;
		if (i == 0)
			count += (piles->len_total % piles->chunks);
		piles->mediane[i] = find_median(piles, count, min);
		min = piles->mediane[i] + 1;
		i++;
	}
}
