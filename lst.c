#include <stdio.h>

int *longest_of_lis(int *stack, int size)
{
	int **back_tracking;
	int i;
	int *lis;
	int lis_size;
	int first;
	int j;
	int len;

	i = 0;
	lis_size = 0;
	first = 0;
	len = 0;
	back_tracking = malloc(size * sizeof(* int));
	while ()
	{
		j = i + 1;
		while (i < size)
		{
			if (stack[i] < stack[j])
			{
				len++;
				if (!first)
				{
					back_tracking[j][0] = stack[j];
					back_tracking[j][1] = stack[j];
					first = 1;
				}
			}
			j++;
		}
		if 
	}
}
