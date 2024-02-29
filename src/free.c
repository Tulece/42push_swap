/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:55:12 by anporced          #+#    #+#             */
/*   Updated: 2024/02/29 21:03:10 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_lst_ab(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*current;
	t_lst	*next;

	current = *lst_a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	current = *lst_b;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
