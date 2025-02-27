#include <stdlib.h>
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

int *lis(int *stack, int size)
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
	while (index < size)
	{
		j = index + 1;
		i = 0;
		distance = 5555;
		len = 0;
		while (ignored_size > 0 && ignored_elements(stack[index], index, ignored, ignored_size))
			index++;
		printf("element %d index %d\n", stack[index], index);
		while (j < size)
		{
		//	printf("index %d j--->%d\n", stack[j], j);
			if (stack[index] < stack[j] && (stack[j] - stack[index]) < distance)
			{
				if ((!ignored_elements(stack[j], j, ignored, ignored_size)))
				{
					distance = stack[j] - stack[index];
					save = j;
				}
			}
			j++;
		}
		best_index = save;
		//printf("best_index is -->%d\n", stack[best_index]);
		while (save > index)
		{
			if (best_index - 1 == index)
				break;
			j = save + 1;
			i = save;
			while (i < size)
			{
				if (stack[i] < stack[j])
					len ++;
				i++;
			}
			if (len < prev_len)
			{
				best_index = save;
			}
			prev_len = len;
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
		for (int i = 0; ignored_size > i; i += 2)
			printf("ignoreddd--->%d index %d\n", ignored[i], ignored[i + 1]);
		printf("---------------------\n");
		
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
	for (int i = 0; best_stack_size > i; i++)
		printf("best_stack--->%d\n", best_stack[i]);
	return stack;
}
int main()
{
	int stack[16] = {1, 2, 3, 10, 12, 5, 4, 6, 13, 18, 15, 7, 9, 300, 30, 101}; 
	lis(stack, 16);
}
