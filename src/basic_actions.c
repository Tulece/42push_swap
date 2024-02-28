/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:18:18 by anporced          #+#    #+#             */
/*   Updated: 2024/02/28 14:17:36 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_lst **src, t_lst **dst)
{
	t_lst	*aux;

	if (!*src)
		return ;
	aux = *src;
	*src = aux->next;
	lst_add_front(dst, aux);
}

void	rotate(t_lst **lst)
{
	t_lst	*aux;

	aux = *lst;
	if (lst_size(*lst) < 2)
		return ;
	*lst = (*lst)->next;
	aux->next = NULL;
	lst_add_back(lst, aux);
}

void	swap(t_lst **lst)
{
	int	nb;

	if (lst_size(*lst) < 2)
		return ;
	nb = (*lst)->nb;
	(*lst)->nb = (*lst)->next->nb;
	(*lst)->next->nb = nb;
}

void	reverse_rotate(t_lst **lst)
{
	t_lst	*last;
	t_lst	*first;

	if (!(*lst) || !(*lst)->next || lst_size(*lst) < 2)
		return ;
	last = *lst;
	while (last->next->next)
		last = last->next;
	first = last;
	last = last->next;
	last->next = *lst;
	*lst = last;
	first->next = NULL;
}
