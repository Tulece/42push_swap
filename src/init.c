/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:09 by anporced          #+#    #+#             */
/*   Updated: 2024/02/26 12:43:42 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_ab *ab)
{
	ab->lst_a = NULL;
	ab->lst_b = NULL;
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
		ft_printf("%d\n", current->index);
		current = current->next;
		index++;
	}
	index = 0;
	current = ab->lst_b;
	while (current)
	{
		current->index = index;
		ft_printf("%d\n", current->index);
		current = current->next;
		index++;
	}
}
