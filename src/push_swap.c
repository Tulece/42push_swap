/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:12 by anporced          #+#    #+#             */
/*   Updated: 2024/02/28 16:52:30 by anporced         ###   ########.fr       */
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
	print_ab(&ab);
	algorithm(&ab);
	// print_ab(&ab);
	return (0);
}
