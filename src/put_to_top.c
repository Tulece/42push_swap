/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:44:39 by anporced          #+#    #+#             */
/*   Updated: 2024/03/04 19:24:29 by anporced         ###   ########.fr       */
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

	lowest_cost_node = find_lowest_total_cost(&ab->lst_b);
	size = lst_size(ab->lst_b);
	if (lowest_cost_node->index <= size / 2)
		while (ab->lst_b != lowest_cost_node)
			rb(ab);
	else
		while (ab->lst_b != lowest_cost_node)
			rrb(ab);
}
