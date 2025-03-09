/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:48 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:01:49 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack)
{
	int	tmp;

	tmp = stack[1];
	stack[1] = stack[0];
	stack[0] = tmp;
}

void	swap_a(t_utils *utils)
{
	if (utils->element_a < 2)
		return ;
	swap(utils->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_utils *utils)
{
	if (utils->element_b < 2)
		return ;
	swap(utils->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_a_and_b(t_utils *utils)
{
	swap(utils->stack_a);
	swap(utils->stack_b);
	ft_putstr_fd("ss\n", 1);
}
