/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:28 by anporced          #+#    #+#             */
/*   Updated: 2024/03/06 16:06:25 by anporced         ###   ########.fr       */
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

void	algorithm(t_ab *ab)
{
	t_lst	*smallest_node;

	while (lst_size(ab->lst_a) > 3)
		pb(ab);
	tiny_sort(&ab->lst_a, ab);
	while (ab->lst_b)
	{
		set_index(ab);
		find_target(ab);
		set_cost(ab);
		handle_double_rotation(ab);
		pa(ab);
	}
	smallest_node = find_lowest_node(&ab->lst_a);
	set_index(ab);
	if (smallest_node->index > lst_size(ab->lst_a) / 2)
		while (ab->lst_a != smallest_node)
			rra(ab);
	else
		while (ab->lst_a != smallest_node)
			ra(ab);
}
