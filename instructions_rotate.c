/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <aiimdih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:30 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:04:42 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_utils *utils)
{
	int	i;
	int	tmp;

	tmp = utils->stack_a[0];
	i = 0;
	while (i <= utils->element_a)
	{
		utils->stack_a[i] = utils->stack_a[i + 1];
		i++;
	}
	utils->stack_a[utils->element_a - 1] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_utils *utils)
{
	int	i;
	int	tmp;

	tmp = utils->stack_b[0];
	i = 0;
	while (i <= utils->element_b)
	{
		utils->stack_b[i] = utils->stack_b[i + 1];
		i++;
	}
	utils->stack_b[utils->element_b - 1] = tmp;
	ft_putstr_fd("rb\n", 1);
}
