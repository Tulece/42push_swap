/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:28 by anporced          #+#    #+#             */
/*   Updated: 2024/02/28 17:15:24 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_sort(t_lst **lst, t_ab *ab)
{
	t_lst	*highest_node;

	highest_node = find_highest_node(lst);
	if (*lst == highest_node)
		ra(ab);
	else if ((*lst)->next == highest_node)
		rra(ab);
	if ((*lst)->nb > (*lst)->next->nb)
		sa(ab);
}

void	find_target(t_ab *ab)
{
	t_lst	*aux;

	aux = ab->lst_b;
	while (aux)
	{
		aux->target = find_smallest_bigger_node(&ab->lst_a, aux);
		aux = aux->next;
	}
}

void	set_cost(t_ab *ab)
{
	t_lst	*current;

	current = ab->lst_b;
	while (current)
	{
		if (current->index <= lst_size(ab->lst_b) / 2)
		{
			if (current->target->index <= lst_size(ab->lst_a) / 2)
				current->target->cost = current->target->index;
			else
				current->target->cost
					= lst_size(ab->lst_a) - current->target->index;
			if ((current->index <= lst_size(ab->lst_b) / 2
					&& current->target->index <= lst_size(ab->lst_a) / 2)
				|| (current->index > lst_size(ab->lst_b) / 2
					&& current->target->index > lst_size(ab->lst_a) / 2))
			{
				if (current->cost <= current->target->cost)
					current->cost = current->target->cost;
			}
			else
				current->cost = current->cost + current->target->cost;
		}
		current = current->next;
	}
}

void	put_node_to_top_a(t_ab *ab, t_lst *target)
{
	int		size;

	size = lst_size(ab->lst_a);
	if (target->index < size / 2)
		while (ab->lst_a != target)
			ra(ab);
	else
		while (ab->lst_a != target)
			rra(ab);
}

void	put_node_to_top_b(t_ab *ab)
{
	t_lst	*lowest_cost_node;
	int		size;

	lowest_cost_node = find_lowest_cost(&ab->lst_b);
	size = lst_size(ab->lst_b);
	if (lowest_cost_node->index < size / 2)
		while (ab->lst_b != lowest_cost_node)
			rb(ab);
	else
		while (ab->lst_b != lowest_cost_node)
			rrb(ab);
}

void	algorithm(t_ab *ab)
{
	while (lst_size(ab->lst_a) > 3)
		pb(ab);
	while (ab->lst_b)
	{
		//is sorted
		set_index(ab);
		find_target(ab);
		set_cost(ab);
		put_node_to_top_b(ab);
		put_node_to_top_a(ab, ab->lst_b->target);
		pa(ab);
		print_ab(ab);
		// ra ou rra jusqua ce que le plus petit node soit en haut de lst a
	}
}
