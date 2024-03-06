/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:09 by anporced          #+#    #+#             */
/*   Updated: 2024/03/06 16:58:45 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_ab *ab)
{
	ab->lst_a = NULL;
	ab->lst_b = NULL;
}

int	split_argv(int ac, char **av, t_ab *ab)
{
	char	**tab;
	int		i;
	int		j;
	long	nb;

	i = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		j = 0;
		while (tab[j])
		{
			nb = ft_atol(tab[j]);
			if (nb > INT_MAX || nb < INT_MIN
				|| (!check_input(tab[j], nb, ab->lst_a)))
				return (free_tab(tab), 0);
			lst_add_back(&ab->lst_a, lst_new((int)nb));
			j++;
		}
		free_tab(tab);
	}
	return (1);
}

int	is_sorted(t_ab *ab)
{
	t_lst	*lst_a;
	t_lst	*prev;

	prev = ab->lst_a;
	lst_a = ab->lst_a->next;
	while (lst_a)
	{
		if (prev->nb > lst_a->nb)
			return (0);
		prev = lst_a;
		lst_a = lst_a->next;
	}
	return (1);
}
