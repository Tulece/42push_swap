/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:53:31 by anporced          #+#    #+#             */
/*   Updated: 2024/02/26 12:50:12 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
