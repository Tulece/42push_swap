/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:39:12 by anporced          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:59 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int	check_instructions(char *instruction, t_lst **lst_a, t_lst **lst_b);
int	checker(t_ab *ab);

#endif
