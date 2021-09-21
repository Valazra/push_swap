/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/19 17:06:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_piles *piles)
{
	if (piles->len_total == 2)
		two_numbers_sort(piles);
	else if (piles->len_total == 3)
		three_numbers_sort(piles);
	else if (piles->len_total == 4)
		four_numbers_sort(piles);
	else if (piles->len_total == 5)
		five_numbers_sort(piles);
	else
		more_than_five_numbers_sort(piles);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	main2(t_piles *piles)
{
	if (test_sort(piles) == 1)
		free_piles(piles);
	else
	{
		choose_sort(piles);
		free_piles(piles);
	}
}

int	main(int ac, char **av)
{
	t_piles	piles;
	int		k;

	k = 1;
	if (ac == 1)
		return (0);
	while (k < ac)
	{
		if (is_empty(av[k]) == 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		k++;
	}
	init_piles(&piles);
	parsing(ac, av, &piles);
	set_min_max(&piles);
	main2(&piles);
	return (0);
}
