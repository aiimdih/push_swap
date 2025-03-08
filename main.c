/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:54:03 by aiimdih           #+#    #+#             */
/*   Updated: 2025/02/21 13:30:26 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int find_bigger(int *stack, int size)
{
	int tmp;
	int i;
	int j;
	int index;
	
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
	return index;
}

void pre_sort(t_utils *utils)
{
	int i;
	int mid;

	i = 0;
	mid = 0;
	while (i < utils->element_a)
	{
		 mid  = mid + utils->stack_a[i];
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
		
void push_to_b(t_utils *utils)
{
	int bigger_element_index;

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

int my_abs(int num) 
{
    if (num < 0)
        return -num;
    else
        return num;
}

int handle_if_target_smallest(t_utils *utils, int element, int tmp)
{
	int i;
	int bigest_number;

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
	return bigest_number;
}

int get_biggest_number_befor_target(t_utils *utils, int element)
{
	int i;
	int tmp;
	int bigest_number;

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
	return bigest_number;	
}

int count_pos_in_stack_a(int element, t_utils *utils)
{
	int i;
	int bigest_number;

	i = 0;
	bigest_number = get_biggest_number_befor_target(utils, element);
	if (bigest_number > (utils->element_a / 2))
	{
		if (bigest_number > utils->element_a || bigest_number == utils->element_a)
			bigest_number = 0;
		else
			bigest_number = (utils->element_a - bigest_number ) * -1;
	}
	return bigest_number;
}

int count_cost(int cost_to_top, int cost_in_stack_a)
{
	int cost;

	if ((cost_to_top < 0 && cost_in_stack_a < 0) || (cost_to_top > 0 && cost_in_stack_a > 0))
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

void handle_remainder(t_utils *utils, int cost_to_top, int cost_in_stack_a, int remainder)
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

void same_direction(int cost_to_top, int cost_in_stack_a, t_utils *utils)
{
	int remainder;
	int tmp;

	if ((cost_to_top < 0 && cost_to_top < cost_in_stack_a) || (cost_to_top > 0 && cost_to_top > cost_in_stack_a))
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
		if ((cost_in_stack_a < 0 && cost_to_top > cost_in_stack_a) || (cost_in_stack_a > 0 && cost_to_top < cost_in_stack_a))
			remainder = my_abs(cost_in_stack_a) - my_abs(cost_to_top);
		else 
			remainder = my_abs(cost_to_top) - my_abs(cost_in_stack_a);
		handle_remainder(utils, cost_to_top, cost_in_stack_a, remainder);
	}
}

void different_direction(t_utils *utils, int cost_in_stack_a)  
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

void get_lower_cost_info(t_utils *utils, int *lower_cost_element, int *lower_cost_index)
{
	int i;
	int prev_cost;
	int cost_to_top;
	int cost_in_stack_a;
	int cost;

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
		if(cost < prev_cost || prev_cost == -1)
		{
			prev_cost = cost;
			*lower_cost_element = utils->stack_b[i]; 
			*lower_cost_index = i;
		}
		i++;
	}
}

void run_cost(t_utils *utils)
{
	int lower_cost_element;
	int cost_to_top;
	int lower_cost_index;
	int cost_in_stack_a;

	get_lower_cost_info(utils,&lower_cost_element,&lower_cost_index);
	if (lower_cost_index > (utils->element_b / 2))
		cost_to_top = (utils->element_b - lower_cost_index) * -1; 
	else 
		cost_to_top = lower_cost_index;
	cost_in_stack_a = count_pos_in_stack_a(lower_cost_element, utils);
	if ((cost_to_top < 0 && cost_in_stack_a < 0) || (cost_to_top > 0 && cost_in_stack_a > 0))
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
	push_a(utils);
}


void alignment_stack(t_utils *utils)
{
	int bigger_element_index;
	int cost;

	bigger_element_index = find_bigger(utils->stack_a, utils->element_a);
	if (bigger_element_index > (utils->element_a / 2))
	{
		cost = (utils->element_a - 1) - bigger_element_index ;
		while (cost > 0)
		 {
			 reverse_rotate_a(utils);
			 cost--;
		 }
	}
	else {
		cost = bigger_element_index;  
		while (cost >= 0)
		 {
			rotate_a(utils);
			cost--;
		 }
	}
}

int main(int ac, char **av)
{
	t_utils *utils;
	utils = malloc(sizeof(t_utils));
	parse(av, ac, utils);
	utils->lds_stack = malloc(sizeof(utils->element_a));
	push_to_b(utils);
	while (utils->element_b > 0)
		run_cost(utils);
	alignment_stack(utils);
	free(utils);
}
