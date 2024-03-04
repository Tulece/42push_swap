/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:50:45 by anporced          #+#    #+#             */
/*   Updated: 2024/03/04 18:56:52 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_total_cost(t_lst *target_a, t_lst *target_b, t_ab *ab)
{
	int	dir_a;
	int	dir_b;
	int	cost;

	if (target_a->index > lst_size(ab->lst_a) / 2)
		dir_a = -1;
	else
		dir_a = 1;
	if (target_b->index > lst_size(ab->lst_b) / 2)
		dir_b = -1;
	else
		dir_b = 1;
	if (dir_a == dir_b)
	{
		if (target_a->cost > target_b->cost)
			cost = target_a->cost;
		else
			cost = target_b->cost;
	}
	else
		cost = target_a->cost + target_b->cost;
	return (cost);
}

int	get_number_in_common(t_lst *target_a, t_lst *target_b)
{
	int	diff;
	int	nic;

	diff = 0;
	if (target_a->cost > target_b->cost)
		diff = target_a->cost - target_b->cost;
	else
		diff = target_b->cost - target_a->cost;
	if (target_b->cost != target_b->total_cost
		&& target_a->cost != target_b->total_cost)
		nic = 0;
	else
		nic = target_b->total_cost - diff;
	return (nic);
}
