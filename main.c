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

int main(int ac, char **av)
{
	t_utils *utils;
	utils = malloc(sizeof(t_utils));
	parse(av, ac, utils);
	for (int i = 0; i < utils->element_a ; i++)
		printf("utils->stack_a --> : %d\n", utils->stack_a[i]);
	for (int i = 0; i < utils->element_b ; i++)
		printf("utils->stack_b --> : %d\n", utils->stack_b[i]);
	swap_a(utils);
	push_b(utils);
	push_b(utils);
	push_b(utils);
	rotate_a(utils);
	rotate_b(utils);
	reverse_rotate_a_b(utils);
	//reverse_rotate_a_b(utils);
	swap_a(utils);
	push_a(utils);
	push_a(utils);
	push_a(utils);
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
