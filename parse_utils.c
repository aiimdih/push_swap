/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:25:29 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:25:32 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args_len(char **args, int ac)
{
	int	len;
	int	j;

	len = 0;
	j = 1;
	while (j < ac)
	{
		len += ft_strlen(args[j]);
		j++;
	}
	return (len + j);
}

int	check_doubles(t_utils *utils)
{
	int	i;
	int	j;

	i = 0;
	while (i < utils->element_a)
	{
		j = i + 1;
		while (i < utils->element_a && j < utils->element_a)
		{
			if (utils->stack_a[i] == utils->stack_a[j])
				return (FALSE);
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}
