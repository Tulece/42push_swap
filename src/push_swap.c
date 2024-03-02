/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:12 by anporced          #+#    #+#             */
/*   Updated: 2024/03/02 19:56:43 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_ab	ab;

	if (ac < 2)
		return (ft_printf("Error.\n"));
	init(&ab);
	split_argv(ac, av, &ab);
	if (is_sorted(&ab))
		return (0);
	algorithm(&ab);
	// print_ab(&ab);
	// ft_printf("the program is sorted : %d\n", is_sorted(&ab));
	free_lst(&ab);
	return (0);
}
