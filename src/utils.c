/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:55:43 by anporced          #+#    #+#             */
/*   Updated: 2024/03/02 20:29:05 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_ab(t_ab *ab)
{
	t_lst *act_a;
	t_lst *act_b;

	act_a = ab->lst_a;
	act_b = ab->lst_b;
	ft_printf("lst_a :\tlst_b :\n");
	if (act_a)
		ft_printf("%d\t\t", act_a->nb);
	if (act_b)
		ft_printf("%d\t\t\n", act_b->nb);
	else
		ft_printf("\n");
	act_a = act_a->next;
	if (act_b)
		act_b = act_b->next;
	while ((act_a && act_a != ab->lst_a) || (act_b && act_b != ab->lst_b))
	{
		if (act_a && act_a != ab->lst_a)
		{
			ft_printf("%d\t\t", act_a->nb);
			act_a = act_a->next;
		}
		else
			ft_printf("\t\t");
		if (act_b && act_b != ab->lst_b)
		{
			ft_printf("%d\t\n", act_b->nb);
			act_b = act_b->next;
		}
		else
			ft_printf("\t\t\n");
	}
}
