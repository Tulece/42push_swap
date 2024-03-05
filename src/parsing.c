/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:53:31 by anporced          #+#    #+#             */
/*   Updated: 2024/03/05 12:55:08 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_double(t_lst *lst, int nb)
{
	t_lst	*current;

	current = lst;
	while (current)
	{
		if (current->nb == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_input(char *av, long nb, t_lst *lst)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((!ft_isdigit(av[i]) && i != 0) || ((i == 0 && av[i] != '-')
			&& (i == 0 && av[i] != '+') && !ft_isdigit(av[i])))
			return (printf("saucisse\n"), 0);
		if (check_double(lst, (int)nb))
			return (printf("saucisson\t%d\n", i), 0);
		i++;
	}
	return (1);
}
