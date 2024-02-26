/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:28:28 by anporced          #+#    #+#             */
/*   Updated: 2024/02/26 18:22:22 by anporced         ###   ########.fr       */
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

t_lst	*find_highest_node(t_lst **lst)
{
	t_lst	*current;
	t_lst	*highest_node;

	current = *lst;
	highest_node = current;
	while (current)
	{
		if (current->nb > highest_node->nb)
			highest_node = current;
		current = current->next;
	}
	return (highest_node);
}

t_lst	*find_lowest_node(t_lst **lst)
{
	t_lst	*current;
	t_lst	*lowest_node;

	current = *lst;
	lowest_node = current;
	while (current)
	{
		if (current->nb < lowest_node->nb)
			lowest_node = current;
		current = current->next;
	}
	return (lowest_node);
}

t_lst	*find_smallest_bigger_node(t_lst **lst, t_lst *node)
{
	t_lst	*current;
	t_lst	*smallest_bigger_node;
	int		max;

	current = *lst;
	smallest_bigger_node = current;
	max = INT_MAX;
	while (current)
	{
		if (current->nb > node->nb && current->nb < max)
		{
			max = current->nb;
			smallest_bigger_node = current;
			ft_printf("smallest_bigger_node = %d\n", smallest_bigger_node->nb);
		}
		current = current->next;
	}
	return (smallest_bigger_node);
}

// t_lst	*find_smallest_bigger_node(t_lst **lst, t_lst *node)
// {
// 	t_lst	*current;
// 	t_lst	*smallest_bigger_node;
// 	t_lst	*minimum_node;
// 	int		min_nb;
// 	int		max;

// 	current = *lst;
// 	smallest_bigger_node = NULL;
// 	minimum_node = NULL;
// 	max = INT_MAX;
// 	min_nb = INT_MAX;
// 	while (current)
// 	{
// 		if (current->nb < min_nb)
// 		{
// 			min_nb = current->nb;
// 			ft_printf("min_nb = %d\n", min_nb);
// 			minimum_node = current;
// 		}
// 		if (current->nb > node->nb && current->nb < max)
// 		{
// 			max = current->nb;
// 			ft_printf("current->nb = %d\n", current->nb);
// 			smallest_bigger_node = current;
// 		}
// 		current = current->next;
// 	}
// 	if (smallest_bigger_node == NULL)
// 		return (minimum_node);
// 	else
// 		return (smallest_bigger_node);
// }

void	find_target(t_ab *ab)
{
	t_lst	*aux;

	aux = ab->lst_b;
	while (aux)
	{
		aux->target = find_smallest_bigger_node(&ab->lst_a, aux);
		aux = aux->next;
	}
}

void	set_cost(t_ab *ab)
{
	int		len_a;
	int		len_b;
	t_lst	*current;

	len_a = lst_size(ab->lst_a);
	len_b = lst_size(ab->lst_b);
	current = ab->lst_b;
	while (current)
	{
		if (current->index >= len_b / 2)
			current->cost = current->index;
		else
			current->cost = len_b - current->index;
		if (current->target && current->target->index > len_b / 2)
			current->cost += current->target->index;
		else if (current->target)
			current->cost += len_a - current->target->index;
		current = current->next;
	}
}
