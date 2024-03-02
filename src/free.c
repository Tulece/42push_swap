/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:55:12 by anporced          #+#    #+#             */
/*   Updated: 2024/03/02 19:56:04 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_lst(t_ab *ab)
{
	t_lst	*current;
	t_lst	*next;

	current = ab->lst_a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
