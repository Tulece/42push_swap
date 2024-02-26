/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:00:48 by anporced          #+#    #+#             */
/*   Updated: 2024/02/22 18:07:45 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_ab *ab)
{
	ft_printf("pb\n");
	push(&ab->lst_a, &ab->lst_b);
}

void	sb(t_ab *ab)
{
	ft_printf("sb\n");
	swap(&ab->lst_b);
}

void	rb(t_ab *ab)
{
	ft_printf("rb\n");
	rotate(&ab->lst_b);
}

void	rrb(t_ab *ab)
{
	ft_printf("rrb\n");
	reverse_rotate(&ab->lst_b);
}
