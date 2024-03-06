/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:38:35 by anporced          #+#    #+#             */
/*   Updated: 2024/03/06 17:00:32 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	check_instructions(char *instruction, t_lst **lst_a, t_lst **lst_b)
{
	if (!strcmp(instruction, "pa"))
		return (push(lst_b, lst_a), 0);
	if (!strcmp(instruction, "pb"))
		return (push(lst_a, lst_b), 0);
	if (!strcmp(instruction, "ra"))
		return (rotate(lst_a), 0);
	if (!strcmp(instruction, "rb"))
		return (rotate(lst_b), 0);
	if (!strcmp(instruction, "sa"))
		return (swap(lst_a), 0);
	if (!strcmp(instruction, "sb"))
		return (swap(lst_b), 0);
	if (!strcmp(instruction, "rra"))
		return (reverse_rotate(lst_a), 0);
	if (!strcmp(instruction, "rrb"))
		return (reverse_rotate(lst_b), 0);
	if (!strcmp(instruction, "rr"))
		return (rotate(lst_a), rotate(lst_b), 0);
	if (!strcmp(instruction, "rrr"))
		return (reverse_rotate(lst_a), reverse_rotate(lst_b), 0);
	if (!strcmp(instruction, "ss"))
		return (swap(lst_a), swap(lst_b), 0);
	return (1);
}

int	checker(t_ab *ab)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		if (check_instructions(line, &ab->lst_a, &ab->lst_b))
			return (free(line), 1);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_ab	ab;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), 0);
	ab.lst_a = NULL;
	ab.lst_b = NULL;
	if (!split_argv(ac, av, &ab))
		return (free_lst(&ab), ft_putstr_fd("Error\n", 2), 1);
	if (checker(&ab))
		return (free_lst(&ab), ft_putstr_fd("Error\n", 2), 1);
	if (!is_sorted(&ab))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}
