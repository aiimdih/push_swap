/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_combo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:00:56 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:00:57 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_and_b(t_utils *utils)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = utils->stack_a[0];
	while (i <= utils->element_a)
	{
		utils->stack_a[i] = utils->stack_a[i + 1];
		i++;
	}
	utils->stack_a[utils->element_a - 1] = tmp;
	i = 0;
	tmp = utils->stack_b[0];
	while (i <= utils->element_b)
	{
		utils->stack_b[i] = utils->stack_b[i + 1];
		i++;
	}
	utils->stack_b[utils->element_b - 1] = tmp;
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate_a(t_utils *utils)
{
	int	i;
	int	tmp;

	i = utils->element_a - 1;
	tmp = utils->stack_a[i];
	while (i > 0)
	{
		utils->stack_a[i] = utils->stack_a[i - 1];
		i--;
	}
	utils->stack_a[0] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_utils *utils)
{
	int	i;
	int	tmp;

	i = utils->element_b - 1;
	tmp = utils->stack_b[i];
	while (i > 0)
	{
		utils->stack_b[i] = utils->stack_b[i - 1];
		i--;
	}
	utils->stack_b[0] = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_a_b(t_utils *utils)
{
	int	i;
	int	tmp;

	i = utils->element_a - 1;
	tmp = utils->stack_a[i];
	while (i > 0)
	{
		utils->stack_a[i] = utils->stack_a[i - 1];
		i--;
	}
	utils->stack_a[0] = tmp;
	i = utils->element_b - 1;
	tmp = utils->stack_b[i];
	while (i > 0)
	{
		utils->stack_b[i] = utils->stack_b[i - 1];
		i--;
	}
	utils->stack_b[0] = tmp;
	ft_putstr_fd("rrr\n", 1);
}
