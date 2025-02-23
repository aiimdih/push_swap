#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void	free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int count_args_len(char **args, int ac)
{
	int len;
	int j;

	len = 0;
	j = 1;
	while (j < ac)
	{
		len += ft_strlen(args[j]);
		j++;
	}
	return len + j;
}

char *merge_args(char **args, int ac)
{
	int i;
	char *merged_args;

	merged_args = malloc((count_args_len(args, ac) + 1) * sizeof(char));
	merged_args[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(merged_args, args[i]);
		ft_strcat(merged_args, " ");
		i++;
	}

	return merged_args;
}



void check_invalid_args(char *args, int *element, t_utils *utils)
{
	int i;
	int sign;
	long result;

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
		{
			utils->error = TRUE;
			return;
		}
		i++;
	}
	if (args[i] && !(args[i] >= '0' && args[i] <= '9'))
	{
		utils->error = TRUE;
		return ;
	}
	*element = result * sign;
}

int *string_to_array(char **args, int ac, t_utils *utils)
{
	int *array;
	int i;

	i = 0; 
	array = malloc(ac * sizeof(int));
	utils->error = FALSE;
	if (!array)
	{
		free_split(args);
		exit(1);
	}
	while (args[i])//i < ac - 2)
	{
		check_invalid_args(args[i], &array[i], utils);
		if (utils->error)
		{
			free_split(args);
			free(array);
			free(utils);
			write(1, "error\n", ft_strlen("error\n"));
			exit(1);
		}
		i++;
	}
	utils->element_number = i;
	return array;
}

int check_doubles(int *array, t_utils *utils)
{
	int i;
	int j;

	i = 0;
	while ( i < utils->element_number)
	{
		j = i + 1;
		while (array[i] && array[j])
		{
			if (array[i] == array[j])
				return FALSE;
			else
				j ++;
		}
		i++;
	}
	return TRUE;
}

int parse(char **args, int ac)
{
	char *merged_args;
	char **splited_args;
	int *array;
	int args_len; 
	t_utils *utils;

	utils = malloc(sizeof(t_utils));
	args_len = count_args_len(args, ac);
	merged_args = merge_args(args, ac);
	splited_args = ft_split(merged_args, ' ');
	free(merged_args);
	array = string_to_array(splited_args, args_len, utils);
	if (!check_doubles(array, utils))
	{
		free(array);
		write (1, "doubles", ft_strlen("doubles"));
		exit(1);
	}
	for (int i = 0; i < utils->element_number ; i++)
		printf("array --> : %d\n", array[i]);
	free_split(splited_args);
	free(array);
	free(utils);
	return 0;
}
