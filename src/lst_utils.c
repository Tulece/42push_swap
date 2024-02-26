/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:01:41 by anporced          #+#    #+#             */
/*   Updated: 2024/02/26 12:38:32 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*lst_new(int nb)
{
	t_lst	*aux;

	aux = (t_lst *)malloc(sizeof(t_lst));
	if (!aux)
		return (NULL);
	aux->index = 0;
	aux->nb = nb;
	aux->next = NULL;
	return (aux);
}

void	lst_add_front(t_lst **lst, t_lst *aux)
{
	if (!lst || !aux)
		return ;
	if (*lst == NULL)
		*lst = aux;
	else
	{
		aux->next = *lst;
		*lst = aux;
	}
}

void	lst_add_back(t_lst **lst, t_lst *new_lst)
{
	t_lst	*aux;

	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	aux = lst_last(*lst);
	aux->next = new_lst;
}

int	lst_size(t_lst *lst)
{
	int		size;
	t_lst	*aux;

	size = 0;
	aux = lst;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

t_lst	*lst_last(t_lst *lst)
{
	int		size;
	t_lst	*aux;

	size = lst_size(lst);
	aux = lst;
	while (size > 1)
	{
		aux = aux->next;
		size--;
	}
	return (aux);
}
