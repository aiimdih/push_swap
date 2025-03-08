#include "push_swap.h"

int find_bigger(int *stack, int size)
{
	int tmp;
	int i;
	int j;
	int index;
	
	tmp = stack[0]; 
	i = 0;
	index = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		if (tmp < stack[j])
		{
			tmp = stack[j];
			index = j;
		}
		i++;
	}
	return index;
}

int my_abs(int num) 
{
    if (num < 0)
        return -num;
    else
        return num;
}

