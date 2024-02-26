/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:09 by anporced          #+#    #+#             */
/*   Updated: 2024/02/26 17:29:15 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_ab *ab)
{
	ab->lst_a = NULL;
	ab->lst_b = NULL;
	// ab->lst_b->target->index = 0;
}

void	create_lst(t_ab *ab, int nb)
{
	lst_add_back(&ab->lst_a, lst_new(nb));
}

void	set_index(t_ab *ab)
{
	t_lst	*current;
	int		index;

	current = ab->lst_a;
	index = 0;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
	index = 0;
	current = ab->lst_b;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}
