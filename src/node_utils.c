/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:30:05 by anporced          #+#    #+#             */
/*   Updated: 2024/03/02 20:27:03 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_node_to_top_a(t_ab *ab, t_lst *target)
{
	int		size;

	size = lst_size(ab->lst_a);
	if (target->index <= size / 2)
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
	if (lowest_cost_node->index <= size / 2)
		while (ab->lst_b != lowest_cost_node)
			rb(ab);
	else
		while (ab->lst_b != lowest_cost_node)
			rrb(ab);
}

void	rr_or_rrr(t_lst *target_a, t_lst *target_b, int flag, t_ab *ab)
{
	if (flag == 1)
		rrr(ab);
	else if (flag == 0)
		rr(ab);
}

void	double_rotation(t_ab *ab)
{
	t_lst	*target_a;
	t_lst	*target_b;
	int		size_a;
	int		size_b;
	int		i;

	target_b = find_lowest_cost(&ab->lst_b);
	target_a = target_b->target;
	size_a = lst_size(ab->lst_a);
	size_b = lst_size(ab->lst_b);
	i = find_total_cost(target_a, target_b);
	// printf("target_a->cost = %d\t target_b->cost = %d\t i = %d\n", target_a->cost, target_b->cost, i);
	if (target_a->index <= size_a / 2 && target_b->index <= size_b / 2)
		while (i--)
			rr_or_rrr(target_a, target_b, 0, ab);
	else if (target_a->index > size_a / 2 && target_b->index > size_b / 2)
		while (i--)
			rr_or_rrr(target_a, target_b, 1, ab);
	set_index(ab);
	put_node_to_top_b(ab);
	put_node_to_top_a(ab, ab->lst_b->target);
}
