/* ************************************************************************** */
/*                                                                            */
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

int in_lds_stack(int element, t_utils *utils)
{
	int i;

	i = 0;
	while (i < utils->lds_stack_size)
	{
		if (element == utils->lds_stack[i])
			return 1;
		i++;
	}
	return 0;
}
		
void push_to_b(t_utils *utils)
{
	int i;
	int saved;

	i = 0;
	while (i < utils->element_a)
	{
		if (in_lds_stack(utils->stack_a[i], utils) == 0)
		{
			saved = utils->stack_a[i];
			while (utils->stack_a[0] != saved)
			{
				if (i < (utils->element_a / 2))
					reverse_rotate_a(utils);
				else {
					rotate_a(utils);
				}
			}
			push_b(utils);
			i = 0;
		}
		else
			i++;
	}
}

int count_pos_in_stack_a(int element, t_utils *utils)
{
	int i;
	int bigest_number;
	int tmp;

	i = 0;
	bigest_number = 0;
	tmp = utils->stack_a[0]; 
	bigest_number = -1;
	while (utils->element_a > i)
	{
		if (element >= utils->stack_a[i] && tmp <= utils->stack_a[i])
		{
			bigest_number = i;
			tmp = utils->stack_a[i];
		}
		i++;
	}
	i = 0;
	if (bigest_number == -1)
	{
		while (utils->element_a > i)
		{
			if (tmp > utils->stack_a[i])
			{
				bigest_number = i - 1;
				tmp = utils->stack_a[i];
			}
			i++;
		}
	}
	printf("element --> %d position in stack == > %d \n", element, bigest_number);
	return bigest_number;
}

void count_cost(t_utils *utils)
{
	int cost;
	int prev_cost;
	int i;
	int lower_cost_element;
	int cost_to_top;
	int lower_cost_index;
	int cost_in_stack_a;

	i = 0;
	prev_cost = -1;
	while (i < utils->element_b)
	{
		cost_in_stack_a = count_pos_in_stack_a(utils->stack_b[i], utils);
		if (i < (utils->element_b / 2))
			cost_to_top = i - utils->element_b; 
		else 
			cost_to_top = i;
		cost = cost_in_stack_a + cost_to_top;
		if(cost < prev_cost || prev_cost == -1)
		{
			prev_cost = cost;
			lower_cost_element = utils->stack_b[i]; 
			lower_cost_index = i;
		}
		i++;
	}
	printf("lowe cost is --> %d\n", lower_cost_element);
	cost_in_stack_a = count_pos_in_stack_a(lower_cost_element, utils);
	while (cost_in_stack_a >= 0)
	{
		rotate_a(utils);
		cost_in_stack_a--;
	}
	while (utils->stack_b[0] != lower_cost_element)
	{
		if (lower_cost_index < (utils->element_b / 2))
			reverse_rotate_b(utils);
		else {
			rotate_b(utils);
		}
	}
	push_a(utils);
}

int main(int ac, char **av)
{
	t_utils *utils;
	utils = malloc(sizeof(t_utils));
	parse(av, ac, utils);
	utils->lds_stack = malloc(sizeof(utils->element_a));
	lis(utils);
	for (int i = 0; i < utils->element_a ; i++)
		printf("utils->stack_a --> : %d\n", utils->stack_a[i]);
	push_to_b(utils);
	for (int i = 0; i < utils->element_a ; i++)
		printf("stack a after push to b --> : %d\n", utils->stack_a[i]);
	for (int i = 0; i < utils->element_b ; i++)
		printf("utils->stack_b --> : %d\n", utils->stack_b[i]);
	while (utils->element_b > 0)
	{
		count_cost(utils);
		for (int i = 0; i < utils->element_a ; i++)
			printf("new stack a --> : %d\n", utils->stack_a[i]);
		printf("1\n");
	}
	/*count_cost(utils);*/
	/*for (int i = 0; i < utils->element_a ; i++)*/
	/*	printf("stack a after push to b --> : %d\n", utils->stack_a[i]);*/
	/*count_cost(utils);*/
	
	//for (int i = 0; i < utils->element_b ; i++)
		//printf("utils->stack_b --> : %d\n", utils->stack_b[i]);
	//rotate_a(utils);	
	printf("----------------- \n");
	for (int i = 0; i < utils->element_b ; i++)
		printf("utils->stack_b --> : %d\n", utils->stack_b[i]);
	printf("----------------- \n");
	for (int i = 0; i < utils->element_a ; i++)
		printf("utils->stack_a --> : %d\n", utils->stack_a[i]);
}
