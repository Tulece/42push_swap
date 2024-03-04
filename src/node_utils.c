/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:30:05 by anporced          #+#    #+#             */
/*   Updated: 2024/03/04 18:51:45 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr_or_rrr(t_lst *target_a, t_lst *target_b, int flag, t_ab *ab)
{
	if (flag == 1)
		rrr(ab);
	else if (flag == 0)
		rr(ab);
}

void	handle_double_rotation(t_ab *ab)
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
	i = get_number_in_common(target_a, target_b);
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
