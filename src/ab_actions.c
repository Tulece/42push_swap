/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:00:44 by anporced          #+#    #+#             */
/*   Updated: 2024/02/22 18:26:15 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_ab *ab)
{
	ft_printf("rr\n");
	rotate(&ab->lst_a);
	rotate(&ab->lst_b);
}

void	rrr(t_ab *ab)
{
	ft_printf("rrr\n");
	reverse_rotate(&ab->lst_a);
	reverse_rotate(&ab->lst_b);
}

void	ss(t_ab *ab)
{
	ft_printf("ss\n");
	swap(&ab->lst_a);
	swap(&ab->lst_b);
}
