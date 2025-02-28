#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

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

int lis(int *stack, int size)
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
	int *best_stack;
	int best_stack_size;

	best_stack_size = 0;
	ignored_size = 0;
	prev_len = 0;
	index = 0;
	best_stack = malloc(size * sizeof(int));
	ignored = malloc((size * 2) * sizeof(int));
	while (size > index)
	{
		len = 0;
		j = index + 1;
		while (j < size)
		{
			if (stack[index] < stack[j])
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
		ignored[ignored_size] = stack[best_index - 1];
		ignored[ignored_size + 1] = best_index - 1;
		ignored_size += 2;
		best_index--;
	}
	index = 0;
	while (index < size)
	{
		j = index + 1;
		i = 0;
		distance = INT_MAX;
		len = 0;
		while (ignored_size > 0 && ignored_elements(stack[index], index, ignored, ignored_size))
			index++;
		while (j < size)
		{
			if (stack[index] < stack[j] && (stack[j] - stack[index]) < distance)
			{
				if ((!ignored_elements(stack[j], j, ignored, ignored_size)))
				{
					distance = stack[j] - stack[index];
					save = j;
				}
			}
			else if (stack[index] > stack[j])
			{
				ignored[ignored_size] = stack[j];
				ignored[ignored_size + 1] = j;
				ignored_size += 2;
			}
			j++;
		}
		best_index = save;
		prev_len = 0;
		while (save > index)
		{
			if (best_index - 1 == index)
				break;
			j = save + 1;
			if (stack[save] > stack[index])
			{
				while (j < size)
				{
					if (stack[save] < stack[j])
						len ++;
					j++;
				}
				if (len > prev_len)
				{
					prev_len = len;
					best_index = save;
				}
			}
			save--;
		}
		while (best_index > index)
		{
			if (best_index - 1 == index)
				break;
			ignored[ignored_size] = stack[best_index - 1];
			ignored[ignored_size + 1] = best_index - 1;
			ignored_size += 2;
			best_index--;
		}
		
		index++;
		//return stack;
	}
	index = 0;
	i = 0;

	while (index < size)
	{
		if (!ignored_elements(stack[index], index, ignored, ignored_size))
		{
			best_stack[i] = stack[index];
			best_stack_size++;
			i++;
		}
		index++;
	}
	return ignored_size / 2;
}
int main()
{
	int stack[7] = {7, 6, 5, 4, 3, 2 ,1}; 
	lis(stack, 7);
}
