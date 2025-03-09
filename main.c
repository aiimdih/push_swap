/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <aiimdih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:30:26 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/08 23:26:47 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	alignment_stack(t_utils *utils)
{
	int	bigger_element_index;
	int	cost;

	bigger_element_index = find_bigger(utils->stack_a, utils->element_a);
	if (bigger_element_index > (utils->element_a / 2))
	{
		cost = (utils->element_a - 1) - bigger_element_index;
		while (cost > 0)
		{
			reverse_rotate_a(utils);
			cost--;
		}
	}
	else
	{
		cost = bigger_element_index;
		while (cost >= 0)
		{
			rotate_a(utils);
			cost--;
		}
	}
}

int	main(int ac, char **av)
{
	t_utils	*utils;

	utils = malloc(sizeof(t_utils));
	parse(av, ac, utils);
	utils->lds_stack = malloc(sizeof(utils->element_a));
	push_to_b(utils);
	while (utils->element_b > 0)
	{
		run_cost(utils);
		push_a(utils);
	}
	alignment_stack(utils);
	free(utils);
}
