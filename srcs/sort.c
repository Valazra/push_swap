/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/16 16:20:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_dir_and_count(t_piles *piles, long pos, long *count, int *dir)
{
	if (pos == -1)
		ft_error(piles);
	if (pos > (piles->len_pile_a / 2) + 1)
	{
		*dir = 0;
		*count = piles->len_pile_a - pos;
		if (*count < 0)
			*count = 0;
	}
	else
	{
		*dir = 1;
		*count = pos;
	}
}

long	find_pos_min_or_max(t_list *list, long min_or_max)
{
	t_list	*tmp;
	long	count;

	tmp = list;
	count = 0;
	while (tmp)
	{
		if (min_or_max == tmp->content)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (-1);
}

void	min_first_place(t_piles *piles)
{
	int		dir;
	long	pos;
	long	count;

	pos = find_pos_min_or_max(piles->a, piles->min);
	set_dir_and_count(piles, pos, &count, &dir);
	if (dir)
	{
		while (count > 0)
		{
			op_ra(piles);
			count--;
		}
	}
	else
	{
		while (count > 0)
		{
			op_rra(piles);
			count--;
		}
	}
}

int	test_sort(t_piles *piles)
{
	t_list	*list;

	if (!piles)
		return (0);
	list = piles->a;
	if (!list)
		return (0);
	while (list->next != NULL)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
