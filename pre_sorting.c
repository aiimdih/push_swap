/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:02:19 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:02:20 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(t_utils *utils)
{
	int	i;
	int	mid;

	i = 0;
	mid = 0;
	while (i < utils->element_a)
	{
		mid = mid + utils->stack_a[i];
		i++;
	}
	mid /= utils->element_a;
	i = 0;
	while (utils->element_a > 3)
	{
		if (utils->stack_a[i] < mid)
		{
			push_b(utils);
			rotate_b(utils);
		}
		else
			push_b(utils);
	}
}

void	push_to_b(t_utils *utils)
{
	int	bigger_element_index;

	pre_sort(utils);
	bigger_element_index = find_bigger(utils->stack_a, utils->element_a);
	if (utils->element_a == 3)
	{
		if (bigger_element_index != utils->element_a - 1)
		{
			if (bigger_element_index == 0)
				rotate_a(utils);
			else if (bigger_element_index == 1)
				reverse_rotate_a(utils);
		}
		if (utils->stack_a[0] > utils->stack_a[1])
			swap_a(utils);
	}
}
