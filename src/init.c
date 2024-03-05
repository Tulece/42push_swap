/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:09 by anporced          #+#    #+#             */
/*   Updated: 2024/03/05 10:56:35 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_ab *ab)
{
	ab->lst_a = NULL;
	ab->lst_b = NULL;
}

void	split_argv(int ac, char **av, t_ab *ab)
{
	char	**tab;
	int		i;
	int		j;
	long	nb;

	i = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		j = -1;
		while (tab[++j])
		{
			nb = ft_atol(tab[j]);
			if (nb > INT_MAX || nb < INT_MIN
				|| (!check_input(av[i], nb, ab->lst_a)))
				return (free_tab(tab));
			lst_add_back(&ab->lst_a, lst_new(nb));
		}
		free_tab(tab);
	}
}
