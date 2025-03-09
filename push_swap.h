/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <aiimdih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:24:39 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:24:56 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_utils
{
	int	element_a;
	int	element_b;
	int	error;
	int	*stack_a;
	int	*stack_b;
	int	*lds_stack;
	int	lds_stack_size;
	int	lds_limitter;
}		t_utils;

typedef struct rrrs_instrictions
{
	int	remainder;
	int	a_or_b;
}		t_rrrs;
void	parse(char **args, int ac, t_utils *utils);
void	swap(int *stack);
void	swap_a(t_utils *utils);
void	swap_b(t_utils *utils);
void	swap_a_and_b(t_utils *utils);
void	push_a(t_utils *utils);
void	push_b(t_utils *utils);
void	rotate_a(t_utils *utils);
void	rotate_b(t_utils *utils);
void	rotate_a_and_b(t_utils *utils);
void	reverse_rotate_a(t_utils *utils);
void	reverse_rotate_b(t_utils *utils);
void	reverse_rotate_a_b(t_utils *utils);
void	run_cost(t_utils *utils);
void	same_direction(int cost_to_top, int cost_in_stack_a, t_utils *utils);
void	different_direction(t_utils *utils, int cost_in_stack_a);
void	run_cost(t_utils *utils);
void	push_to_b(t_utils *utils);
int		find_bigger(int *stack, int size);
int		get_biggest_number_befor_target(t_utils *utils, int element);
int		my_abs(int num);
void	handle_remainder(t_utils *utils, int cost_to_top, int cost_in_stack_a,
			int remainder);
void	free_split(char **ptr);
int		count_args_len(char **args, int ac);
int		check_doubles(t_utils *utils);
#endif
