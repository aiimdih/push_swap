/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <aiimdih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:13 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:04:34 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up(int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	push_a(t_utils *utils)
{
	int	i;
	int	prev;
	int	tmp_1;

	if (utils->element_b < 1)
		return ;
	i = 0;
	prev = utils->stack_a[i + 1];
	utils->stack_a[i + 1] = utils->stack_a[i];
	i++;
	while (i < utils->element_a)
	{
		tmp_1 = utils->stack_a[i + 1];
		utils->stack_a[i + 1] = prev;
		prev = tmp_1;
		i++;
	}
	utils->stack_a[0] = utils->stack_b[0];
	shift_up(utils->stack_b, utils->element_b);
	utils->element_b--;
	utils->element_a++;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_utils *utils)
{
	int	i;
	int	prev;
	int	tmp_1;

	if (utils->element_a < 1)
		return ;
	i = 0;
	prev = utils->stack_b[i + 1];
	utils->stack_b[i + 1] = utils->stack_b[i];
	i++;
	while (i < utils->element_b)
	{
		tmp_1 = utils->stack_b[i + 1];
		utils->stack_b[i + 1] = prev;
		prev = tmp_1;
		i++;
	}
	utils->stack_b[0] = utils->stack_a[0];
	shift_up(utils->stack_a, utils->element_a);
	utils->element_a--;
	utils->element_b++;
	ft_putstr_fd("pb\n", 1);
}
