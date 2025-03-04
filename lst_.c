#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "push_swap.h"

int ignored_elements(int element, int index, int *ignored, int size)
{
	int i;

	i = 0;

	while (i < size)
	{

	//	printf("element %d index %d, igbored element %d, ignored element index %d\n", element, index, ignored[i], ignored[i + 1]);
		if (ignored[i] == element && ignored[i + 1] == index)
		{
			return 1;
		}
		i += 2;
	}
	return 0;
}
void ignore_to_firs_index(int *ignored, int *ignored_size, t_utils *utils)
{
	int best_index;
	int len;
	int j;
	int prev_len;
	int index;

	index = 0;
	prev_len = 0;
	best_index = 0;
	while (utils->element_a > index)
	{
		len = 0;
		j = index + 1;
		while (j < utils->element_a)
		{
			if (utils->stack_a[index] < utils->stack_a[j])
				len ++;
			j++;
		}
		if (len > prev_len)
		{
			prev_len = len;
			best_index = index;
		}
		index++;
	}
	while (best_index > 0)
	{
		ignored[*ignored_size] = utils->stack_a[best_index - 1];
		ignored[*ignored_size + 1] = best_index - 1;
		*ignored_size += 2;
		best_index--;
	}
}
void lis(t_utils *utils)
{
	int distance;
	int j;
	int index;
	int save;
	int len;
	int *ignored;
	int ignored_size;
	int prev_len;
	int best_index;
	int i;

	ignored_size = 0;
	prev_len = 0;
	index = 0;
	ignored = malloc((utils->element_a * 1000000) * sizeof(int));
	ignore_to_firs_index(ignored, &ignored_size, utils);
	index = 0;
	while (index < utils->element_a)
	{
		i = 0;
		distance = INT_MAX;
		len = 0;
		save = -1;
		while (index < utils->element_a && ignored_size > 0 && ignored_elements(utils->stack_a[index], index, ignored, ignored_size))
			index++;
		j = index + 1;
		while (j < utils->element_a)
		{
			if (utils->stack_a[index] < utils->stack_a[j] && (utils->stack_a[j] - utils->stack_a[index]) < distance && utils->stack_a[index] != utils->stack_a[j])
			{
				if ((!ignored_elements(utils->stack_a[j], j, ignored, ignored_size)))
				{
					distance = utils->stack_a[j] - utils->stack_a[index];
					save = j;
				}
			}
			else if (utils->stack_a[index] >= utils->stack_a[j])
			{
//				printf("ignored %d < stack index %d\n", stack[j], stack[index]);
				ignored[ignored_size] = utils->stack_a[j];
				ignored[ignored_size + 1] = j;
				ignored_size += 2;
			}
			j++;
		}
		if (save == -1)
		{
			index++;
			continue;
		}
		best_index = save;
		prev_len = 0;
		while (save > index)
		{
			if (best_index - 1 == index)
				break;
			len = 0;
			i = save;
			j = save + 1;
			if (utils->stack_a[save] > utils->stack_a[index])
			{
				while (j < utils->element_a)
				{
//					printf("stack j %d stack save %d\n", stack[j], stack[save]);
					if (utils->stack_a[i] < utils->stack_a[j])
					{
						len ++;
						i = j;
					}
					j++;
				}
//				printf("len -->%d best stack --> %d\n", len, stack[save]);
				if (len > prev_len)
				{
					prev_len = len;
					best_index = save;
				}
			}
			save--;
		}
		while (best_index > index && (ignored_size + 2) <= 2 * utils->element_a)
		{
			if (best_index - 1 == index)
				break;
			ignored[ignored_size] = utils->stack_a[best_index - 1];
			ignored[ignored_size + 1] = best_index - 1;
			ignored_size += 2;
			best_index--;
		}
		
		index++;
		//return stack;
	}
	index = 0;
	i = 0;
	utils->lds_stack_size = 0;
	while (index < utils->element_a)
	{
		if (!ignored_elements(utils->stack_a[index], index, ignored, ignored_size))
		{
			utils->lds_stack[i] = utils->stack_a[index];
			utils->lds_stack_size++;
			i++;
		}
		index++;
	}
	for (int i = 0; i < utils->lds_stack_size; i++)
		printf("best stack %d\n",  utils->lds_stack[i]);
}
