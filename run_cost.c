/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <aiimdih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:02:50 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:16:08 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_pos_in_stack_a(int element, t_utils *utils)
{
	int	i;
	int	bigest_number;

	i = 0;
	bigest_number = get_biggest_number_befor_target(utils, element);
	if (bigest_number > (utils->element_a / 2))
	{
		if (bigest_number > utils->element_a
			|| bigest_number == utils->element_a)
			bigest_number = 0;
		else
			bigest_number = (utils->element_a - bigest_number) * -1;
	}
	return (bigest_number);
}

int	count_cost(int cost_to_top, int cost_in_stack_a)
{
	int	cost;

	if ((cost_to_top < 0 && cost_in_stack_a < 0) || (cost_to_top > 0
			&& cost_in_stack_a > 0))
	{
		if (cost_to_top > cost_in_stack_a)
		{
			if (cost_to_top < 0)
				cost = my_abs(cost_in_stack_a);
			else
				cost = my_abs(cost_to_top);
		}
		else
		{
			if (cost_to_top > 0)
				cost = my_abs(cost_in_stack_a);
			else
				cost = my_abs(cost_to_top);
		}
	}
	else
		cost = my_abs(cost_in_stack_a) + my_abs(cost_to_top);
	return (cost);
}

void	handle_remainder(t_utils *utils, int cost_to_top, int cost_in_stack_a,
		int remainder)
{
	if (cost_to_top < 0)
	{
		while (remainder-- > 0)
		{
			if (cost_to_top > cost_in_stack_a)
				reverse_rotate_a(utils);
			else
				reverse_rotate_b(utils);
		}
	}
	else
	{
		while (remainder-- > 0)
		{
			if (cost_to_top > cost_in_stack_a)
				rotate_b(utils);
			else
				rotate_a(utils);
		}
	}
}

void	get_lower_cost_info(t_utils *utils, int *lower_cost_element,
		int *lower_cost_index)
{
	int	i;
	int	prev_cost;
	int	cost_to_top;
	int	cost_in_stack_a;
	int	cost;

	i = 0;
	prev_cost = -1;
	while (i < utils->element_b)
	{
		cost_in_stack_a = count_pos_in_stack_a(utils->stack_b[i], utils);
		if (i > (utils->element_b / 2))
			cost_to_top = (utils->element_b - i) * -1;
		else
			cost_to_top = i;
		cost = count_cost(cost_to_top, cost_in_stack_a);
		if (cost < prev_cost || prev_cost == -1)
		{
			prev_cost = cost;
			*lower_cost_element = utils->stack_b[i];
			*lower_cost_index = i;
		}
		i++;
	}
}

void	run_cost(t_utils *utils)
{
	int	lower_cost_element;
	int	cost_to_top;
	int	lower_cost_index;
	int	cost_in_stack_a;

	get_lower_cost_info(utils, &lower_cost_element, &lower_cost_index);
	if (lower_cost_index > (utils->element_b / 2))
		cost_to_top = (utils->element_b - lower_cost_index) * -1;
	else
		cost_to_top = lower_cost_index;
	cost_in_stack_a = count_pos_in_stack_a(lower_cost_element, utils);
	if ((cost_to_top < 0 && cost_in_stack_a < 0) || (cost_to_top > 0
			&& cost_in_stack_a > 0))
		same_direction(cost_to_top, cost_in_stack_a, utils);
	else
	{
		different_direction(utils, cost_in_stack_a);
		while (utils->stack_b[0] != lower_cost_element)
		{
			if (lower_cost_index > (utils->element_b / 2))
				reverse_rotate_b(utils);
			else
				rotate_b(utils);
		}
	}
}
