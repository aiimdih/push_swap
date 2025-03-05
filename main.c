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

void fill_the_stack(t_utils *utils,int index,int size)
{
	int i;

	i = 0;
	utils->lds_stack_size = 0;
	while (index <= size)
	{
		utils->lds_stack[i] = utils->stack_a[index];  
		utils->lds_stack_size++;
		i++;
		index++;
	}
}
void longest_stack(t_utils *utils)
{
	int i;
	int len;
	int j;
	int save;
	int prev_len;
	int tmp;

	save = 0;
	prev_len = 0;
	while (save < utils->element_a)
	{
		len = 0;
		i = save;
		j = save + 1;
		if (utils->stack_a[save] < utils->stack_a[j])
		{
			tmp = utils->stack_a[i];
			while (tmp < utils->stack_a[j])
			{
				tmp = utils->stack_a[j];
				len ++;
				j++;
			}

			if (len > prev_len)
			{
				prev_len = len;
				fill_the_stack(utils, save, len);
			}
		}
		save++;
	}
	/*printf("size of new stack %d\n", utils->lds_stack_size);*/
	/*for (int i = 0; i < utils->lds_stack_size; i++)*/
	/*	printf("best stack %d \n",  utils->lds_stack[i]);*/

}
int in_lds_stack(int element, t_utils *utils)
{
	int i;

	i = 0;
	while (i < utils->lds_stack_size)
	{
		if (element == utils->lds_stack[i])
		{
			utils->lds_limitter += utils->lds_limitter ;
			return 1;
		}
		i++;
	}
	return 0;
}
		
void push_to_b(t_utils *utils)
{
	int i;

	i = 0;
	while (utils->element_a > 3)
	{
		push_b(utils);
	}
	if (utils->element_a == 3)
	{
		if (utils->stack_a[0] > utils->stack_a[1])
			swap_a(utils);	
		else if (utils->stack_a[0] > utils->stack_a[2])
			reverse_rotate_a(utils);
		if (utils->stack_a[1] > utils->stack_a[2])
		{
			rotate_a(utils);
			swap_a(utils);
		}
	}

}
/*void push_to_b(t_utils *utils)*/
/*{*/
/*	int i;*/
/*	int count;*/
	/*int saved;*/
/**/
/*	i = 0;*/
/*	count = 0;*/
/*	utils->lds_limitter = 0;*/
/*	printf("%d lds_stack_size\n", utils->lds_stack_size);*/
/*	while (i < utils->element_a && count < utils->lds_stack_size)*/
/*	{*/
/*	printf("-->%d\n", utils->stack_a[i]);*/
/*		if (in_lds_stack(utils->stack_a[i], utils) == 0)*/
/*		{*/
/*			push_b(utils);*/
/*			i = 0;*/
/*		}*/
/*		else*/
/*		{*/
/**/
/*			count++;*/
/*			rotate_a(utils);*/
/*			i++;*/
/*		}*/
/*	}*/
/*}*/

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
		if (element > utils->stack_a[i])
		{
			tmp = utils->stack_a[i];
			break;
		}
		i++;
	}
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
	i = 0;
	if (bigest_number == utils->element_a)
		return 0;
	if (bigest_number == -1)
	{
		bigest_number = 0;
		while (utils->element_a > i)
		{
			if (utils->stack_a[i] > element && tmp > utils->stack_a[i])
			{
				bigest_number = i;
				tmp = utils->stack_a[i];
			}
			i++;
		}
	}
	if (bigest_number > (utils->element_a / 2))
	{
		if (bigest_number > utils->element_a)
			bigest_number = 0;
		else {
			bigest_number = (utils->element_a - bigest_number ) * -1;
		}
	}
	//printf("element --> %d position in stack == > %d \n", element, bigest_number);
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
		if (i > (utils->element_b / 2))
		{
			cost_to_top = utils->element_b - i; 
		}
		else 
			cost_to_top = i;
		if (cost_in_stack_a < 0)
			cost = (cost_in_stack_a * -1) + cost_to_top;
		else {
			cost = cost_in_stack_a + cost_to_top;
		}
	 	/*printf("the cost of element utils->stack_b %d is ==> %d index %d cost to top %d cost_in_stack_a %d\n", utils->stack_b[i], cost, i, cost_to_top, cost_in_stack_a);*/
	
		if(cost < prev_cost || prev_cost == -1)
		{
			prev_cost = cost;
			lower_cost_element = utils->stack_b[i]; 
			lower_cost_index = i;
		}
		i++;
	}
	/*printf("lowe cost is --> %d\n", lower_cost_element);*/
	cost_in_stack_a = count_pos_in_stack_a(lower_cost_element, utils);
	/*printf("cost in a --> %d\n", cost_in_stack_a);*/
	if (cost_in_stack_a >= 0)
	{
		while (cost_in_stack_a > 0)
		{
			rotate_a(utils);
			cost_in_stack_a--;
		}
	}
	else {
		while (cost_in_stack_a < 0)
		{
			reverse_rotate_a(utils);
			cost_in_stack_a++;
		}
	}
	while (utils->stack_b[0] != lower_cost_element)
	{
		if (lower_cost_index > (utils->element_b / 2))
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
	/*longest_stack(utils);*/
	/*printf("k\n");*/
	/*for (int i = 0; i < utils->element_a ; i++)*/
	/*	printf("utils->stack_a --> : %d\n", utils->stack_a[i]);*/
	push_to_b(utils);
	/*for (int i = 0; i < utils->element_a ; i++)*/
	/*	printf("stack a after push to b --> : %d\n", utils->stack_a[i]);*/
	/*for (int i = 0; i < utils->element_b ; i++)*/
	/*	printf("utils->stack_b --> : %d\n", utils->stack_b[i]);*/
	while (utils->element_b > 0)
	{
		count_cost(utils);
		/*for (int i = 0; i < utils->element_a ; i++)*/
		/*	printf("new stack a --> : %d\n", utils->stack_a[i]);*/
		/*for (int i = 0; i < utils->element_b ; i++)*/
		/*	printf("utils->stack_b --> : %d\n", utils->stack_b[i]);*/
		/*printf("1\n");*/
	}
	/*count_cost(utils);*/
	/*for (int i = 0; i < utils->element_a ; i++)*/
	/*	printf("stack a after push to b --> : %d\n", utils->stack_a[i]);*/
	/*count_cost(utils);*/
	
	//for (int i = 0; i < utils->element_b ; i++)
		//printf("utils->stack_b --> : %d\n", utils->stack_b[i]);
	//rotate_a(utils);	
	/*printf("----------------- \n");*/
	/*for (int i = 0; i < utils->element_b ; i++)*/
	/*	printf("utils->stack_b --> : %d\n", utils->stack_b[i]);*/
	/*printf("----------------- \n");*/
	/*for (int i = 0; i < utils->element_a ; i++)*/
		/*printf("utils->stack_a --> : %d\n", utils->stack_a[i]);*/
}
