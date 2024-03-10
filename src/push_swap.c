/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <anporced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:50:12 by anporced          #+#    #+#             */
/*   Updated: 2024/03/10 15:50:27 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_ab	ab;

	if (ac < 2)
		return (0);
	init(&ab);
	if (!split_argv(ac, av, &ab))
		return (free_lst(&ab), ft_putstr_fd("Error\n", 2), 0);
	if (is_sorted(&ab))
		return (free_lst(&ab), 0);
	algorithm(&ab);
	free_lst(&ab);
	return (0);
}
