/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:12 by anporced          #+#    #+#             */
/*   Updated: 2024/02/26 18:24:14 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_ab	ab;

	if (ac < 2)
		return (ft_printf("Error.\n"));
	init(&ab);
	split_argv(ac, av, &ab);
	set_index(&ab);
	print_ab(&ab);
	pb(&ab);
	print_ab(&ab);
	pb(&ab);
	print_ab(&ab);
	pb(&ab);
	print_ab(&ab);
	pb(&ab);
	print_ab(&ab);
	pb(&ab);
	tiny_sort(&ab.lst_a, &ab);
	print_ab(&ab);
	find_target(&ab);
	set_cost(&ab);
	return (0);
}
