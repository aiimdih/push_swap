/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiimdih <aiimdih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:00:03 by aiimdih           #+#    #+#             */
/*   Updated: 2025/03/09 16:25:57 by aiimdih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

char	*merge_args(char **args, int ac)
{
	int		i;
	char	*merged_args;

	merged_args = malloc((count_args_len(args, ac) + 1) * sizeof(char));
	merged_args[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(merged_args, args[i]);
		ft_strcat(merged_args, " ");
		i++;
	}
	return (merged_args);
}

int	check_invalid_args(char *args, int stack_index, t_utils *utils)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	if (args[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (args[i] == '+')
		i++;
	while (args[i] != '\0' && args[i] >= '0' && args[i] <= '9')
	{
		result *= 10;
		result += args[i] - '0';
		if (result * sign > INT_MAX || (result * sign) < INT_MIN)
			return (utils->error = TRUE, 0);
		i++;
	}
	if (args[i] && !(args[i] >= '0' && args[i] <= '9'))
		return (utils->error = TRUE, 0);
	return (utils->stack_a[stack_index] = result * sign, 1);
}

int	*string_to_array(char **args, int ac, t_utils *utils)
{
	int	i;

	i = 0;
	utils->stack_a = malloc(ac * sizeof(int));
	utils->error = FALSE;
	if (!utils->stack_a)
	{
		free_split(args);
		exit(1);
	}
	while (args[i])
	{
		check_invalid_args(args[i], i, utils);
		if (utils->error)
		{
			free_split(args);
			free(utils->stack_a);
			free(utils);
			write(1, "error\n", ft_strlen("error\n"));
			exit(1);
		}
		i++;
	}
	utils->element_a = i;
	return (0);
}

void	parse(char **args, int ac, t_utils *utils)
{
	char	*merged_args;
	char	**splited_args;
	int		args_len;

	args_len = count_args_len(args, ac);
	merged_args = merge_args(args, ac);
	splited_args = ft_split(merged_args, ' ');
	free(merged_args);
	string_to_array(splited_args, args_len, utils);
	if (!check_doubles(utils))
	{
		free_split(splited_args);
		free(utils->stack_a);
		free(utils);
		write(1, "doubles", ft_strlen("doubles"));
		exit(1);
	}
	free_split(splited_args);
	utils->stack_b = malloc(utils->element_a * sizeof(int));
	utils->element_b = 0;
}
