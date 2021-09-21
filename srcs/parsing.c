/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:10:16 by vazra             #+#    #+#             */
/*   Updated: 2021/09/19 17:44:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isspace(char *str, int *i)
{
	while (str[*i] == '\f' || str[*i] == '\n' || str[*i] == '\r'
		|| str[*i] == '\t' || str[*i] == '\v' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == 0)
		return (0);
	return (1);
}

void	set_values(t_piles *piles, int nb)
{
	t_list	*new;

	new = ft_lstnew(nb);
	if (!new)
		ft_error(piles);
	if (piles->len_total == 0)
		piles->a = new;
	else
		ft_lstadd_back(&piles->a, new);
	piles->len_total++;
	piles->len_pile_a++;
}

int	recup_values(char *str, t_piles *piles, int *i)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		ft_error(piles);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb *= 10;
		nb += str[*i] - '0';
		(*i)++;
	}
	nb *= sign;
	if (nb < (-2147483648) || nb > 2147483647)
		ft_error(piles);
	set_values(piles, (int)(nb));
	return (check_isspace(str, i));
}

void	check_av(char *str, t_piles *piles)
{
	int	i;
	int	stop;

	i = 0;
	stop = 1;
	while (stop)
		stop = recup_values(str, piles, &i);
}

void	parsing(int ac, char **av, t_piles *piles)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		check_av(av[i], piles);
		i++;
	}
	if (check_duplicate(piles) == 1)
		ft_error(piles);
}
