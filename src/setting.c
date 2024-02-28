/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:40:52 by anporced          #+#    #+#             */
/*   Updated: 2024/02/28 16:00:22 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*find_highest_node(t_lst **lst)
{
	t_lst	*current;
	t_lst	*highest_node;

	current = *lst;
	highest_node = current;
	while (current)
	{
		if (current->nb > highest_node->nb)
			highest_node = current;
		current = current->next;
	}
	return (highest_node);
}

t_lst	*find_lowest_node(t_lst **lst)
{
	t_lst	*current;
	t_lst	*lowest_node;

	current = *lst;
	lowest_node = *lst;
	while (current)
	{
		if (current->nb < lowest_node->nb)
			lowest_node = current;
		current = current->next;
	}
	return (lowest_node);
}

t_lst	*find_smallest_bigger_node(t_lst **lst, t_lst *node)
{
	t_lst	*current;
	t_lst	*smallest_bigger_node;
	int		max;

	current = *lst;
	smallest_bigger_node = current;
	max = INT_MAX;
	while (current)
	{
		if (current->nb > node->nb && current->nb < max)
		{
			max = current->nb;
			smallest_bigger_node = current;
		}
		current = current->next;
	}
	if (max == INT_MAX)
		return (find_lowest_node(lst));
	return (smallest_bigger_node);
}

t_lst	*find_lowest_cost(t_lst **lst)
{
	t_lst	*aux;
	t_lst	*lowest;

	aux = *lst;
	lowest = *lst;
	while (aux)
	{
		if (aux->cost < lowest->cost)
			lowest = aux;
		aux = aux->next;
	}
	printf("lowest cost = %d\n", lowest->cost);
	return (lowest);
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
