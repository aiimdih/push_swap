/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:00:36 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:00:37 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_direction(int cost_to_top, int cost_in_stack_a, t_utils *utils)
{
	int	remainder;
	int	tmp;

	if ((cost_to_top < 0 && cost_to_top < cost_in_stack_a) || (cost_to_top > 0
			&& cost_to_top > cost_in_stack_a))
		tmp = my_abs(cost_in_stack_a);
	else
		tmp = my_abs(cost_to_top);
	while (tmp-- > 0)
	{
		if (cost_to_top < 0)
			reverse_rotate_a_b(utils);
		else
			rotate_a_and_b(utils);
	}
	if (cost_in_stack_a != cost_to_top)
	{
		if ((cost_in_stack_a < 0 && cost_to_top > cost_in_stack_a)
			|| (cost_in_stack_a > 0 && cost_to_top < cost_in_stack_a))
			remainder = my_abs(cost_in_stack_a) - my_abs(cost_to_top);
		else
			remainder = my_abs(cost_to_top) - my_abs(cost_in_stack_a);
		handle_remainder(utils, cost_to_top, cost_in_stack_a, remainder);
	}
}

void	different_direction(t_utils *utils, int cost_in_stack_a)
{
	if (cost_in_stack_a >= 0)
	{
		while (cost_in_stack_a > 0)
		{
			rotate_a(utils);
			cost_in_stack_a--;
		}
	}
	else
	{
		while (cost_in_stack_a < 0)
		{
			reverse_rotate_a(utils);
			cost_in_stack_a++;
		}
	}
}
