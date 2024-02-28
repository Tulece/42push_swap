/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:09 by anporced          #+#    #+#             */
/*   Updated: 2024/02/28 15:13:07 by anporced         ###   ########.fr       */
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
	int		nb;

	i = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		j = -1;
		while (tab[++j])
		{
			nb = ft_atoi(tab[j]);
			create_lst(ab, nb);
		}
	}
}

void	create_lst(t_ab *ab, int nb)
{
	lst_add_back(&ab->lst_a, lst_new(nb));
}
