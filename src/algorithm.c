/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:28 by anporced          #+#    #+#             */
/*   Updated: 2024/02/28 18:22:45 by anporced         ###   ########.fr       */
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

// void	ra_or_rra(t_ab *ab)
// {
// 	t_lst	*shortest_node;
// 	t_lst	*current;

// 	shortest_node = ab->lst_a;
// 	current = ab->lst_a;
// 	while (current)
// 	{
// 		if (current->cost < shortest_node->cost)
// 		current = current->next;
// 	}
	// ra ou rra jusqua ce que le plus petit node soit en haut de lst a
// }
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
	}
}
