/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <anporced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:55:12 by anporced          #+#    #+#             */
/*   Updated: 2024/03/10 16:14:24 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_lst(t_ab *ab)
{
	t_lst	*current;
	t_lst	*next;

	current = ab->lst_a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	current = ab->lst_b;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_tab(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}
