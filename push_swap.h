/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:24:39 by aiimdih           #+#    #+#             */
/*   Updated: 2024/02/21 11:26:13 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
typedef struct s_utils
{
	int element_a;
	int element_b;
	int error;
	int *stack_a;
	int *stack_b;
	int *lds_stack;
	int lds_stack_size;
	int lds_limitter;
}					t_utils;

typedef struct rrrs_instrictions 
{
	int remainder;
	int a_or_b;
}					t_rrrs;
void parse(char **args, int ac, t_utils *utils);
void swap(int *stack);
void swap_a(t_utils *utils);
void swap_b(t_utils *utils);
void swap_a_and_b(t_utils *utils);
void push_a(t_utils *utils);
void push_b(t_utils *utils);
void rotate_a(t_utils *utils);
void rotate_b(t_utils *utils);
void rotate_a_and_b(t_utils *utils);
void reverse_rotate_a(t_utils *utils);
void reverse_rotate_b(t_utils *utils);
void reverse_rotate_a_b(t_utils *utils);
void lis(t_utils *utils);
#endif
