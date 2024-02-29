/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:28 by anporced          #+#    #+#             */
/*   Updated: 2024/02/29 12:11:55 by anporced         ###   ########.fr       */
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

void	algorithm(t_ab *ab)
{
	t_lst	*smallest_node;

	while (lst_size(ab->lst_a) > 3)
		pb(ab);
	while (ab->lst_b)
	{
		set_index(ab);
		find_target(ab);
		set_cost(ab);
		put_node_to_top_b(ab);
		put_node_to_top_a(ab, ab->lst_b->target);
		pa(ab);
	}
	smallest_node = find_lowest_node(&ab->lst_a);
	set_index(ab);
	if (smallest_node->index > lst_size(ab->lst_a) / 2)
		while(ab->lst_a != smallest_node)
			rra(ab);
	else
		while(ab->lst_a != smallest_node)
			ra(ab);
}
