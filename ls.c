#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct s_stacks
{
	int *ignored;
	int ignored_size;	
}					t_stacks;

int count_distance(t_stacks *ignored, int *stack, int size)
{
	while (j < size)
	{
		if (stack[index] < stack[j] && (stack[j] - stack[index]) < distance && stack[index] != stack[j])
		{
			if ((!ignored_elements(stack[j], ignored, ignored_size)))
			{
				distance = stack[j] - stack[index];
				save = j;
			}
		}
		else if (stack[index] >= stack[j])
		{
	//				printf("ignored %d < stack index %d\n", stack[j], stack[index]);
			if (!in_ignored(stack[j] , ignored, ignored_size))
			{
				ignored[ignored_size] = stack[j];
				ignored_size ++;
			}
		}
		j++;
	}
}

int	*lds(int *stack, int size)
{
	int distance;
	
	ignored = malloc(sizeof(t_stacks);
	distance = INT_MAX;
	
	while (index < size)
}
