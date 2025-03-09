/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <aiimdih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:03:10 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:05:17 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	find_bigger(int *stack, int size)
{
	int	tmp;
	int	i;
	int	j;
	int	index;

	tmp = stack[0];
	i = 0;
	index = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		if (tmp < stack[j])
		{
			tmp = stack[j];
			index = j;
		}
		i++;
	}
	return (index);
}

int	my_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	handle_if_target_smallest(t_utils *utils, int element, int tmp)
{
	int	i;
	int	bigest_number;

	bigest_number = 0;
	i = 0;
	while (utils->element_a > i)
	{
		if (utils->stack_a[i] > element && tmp > utils->stack_a[i])
		{
			bigest_number = i;
			tmp = utils->stack_a[i];
		}
		i++;
	}
	return (bigest_number);
}

int	get_biggest_number_befor_target(t_utils *utils, int element)
{
	int	i;
	int	tmp;
	int	bigest_number;

	i = 0;
	bigest_number = -1;
	tmp = utils->stack_a[0];
	while (i < utils->element_a && element <= utils->stack_a[i])
		i++;
	if (i < utils->element_a)
		tmp = utils->stack_a[i];
	i = 0;
	while (utils->element_a > i)
	{
		if (element >= utils->stack_a[i] && tmp <= utils->stack_a[i])
		{
			bigest_number = i + 1;
			tmp = utils->stack_a[i];
		}
		i++;
	}
	if (bigest_number == -1)
		bigest_number = handle_if_target_smallest(utils, element, tmp);
	return (bigest_number);
}
