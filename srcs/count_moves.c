/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/15 16:46:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_moves(t_min_or_max *min, t_min_or_max *max, int len)
{
	min->nbr_moves = len - min->pos;
	min->dir = 1;
	if (min->pos < len / 2)
	{
		min->nbr_moves = min->pos;
		min->dir = 0;
	}
	max->nbr_moves = len - max->pos;
	max->dir = 1;
	if (max->pos < len / 2)
	{
		max->nbr_moves = max->pos;
		max->dir = 0;
	}
}

long	set_min_value_and_pos(long nb, long min, long *pos_min, int i)
{
	if (nb < min)
	{
		*pos_min = i;
		min = nb;
	}
	return (min);
}

long	set_max_value_and_pos(long nb, long max, long *pos_max, int i)
{
	if (nb > max)
	{
		*pos_max = i;
		max = nb;
	}
	return (max);
}

void	find_pos(t_list *pile, long *pos_min, long *pos_max)
{
	t_list	*list;
	long	nb;
	long	min;
	long	max;
	int		i;

	list = pile;
	i = 0;
	while (list)
	{
		nb = list->content;
		if (i == 0)
		{
			min = nb;
			max = nb;
			*pos_min = i;
			*pos_max = i;
		}
		min = set_min_value_and_pos(nb, min, pos_min, i);
		max = set_max_value_and_pos(nb, max, pos_max, i);
		i++;
		list = list->next;
	}
}
