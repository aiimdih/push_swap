#include <stdio.h>

int count_pos_in_stack_a(int element, int *stack, int size)
{
	int count;
	int i;
	int bigest_number;
	int tmp;

	i = 0;
	bigest_number = 0;
	tmp = stack[0]; 
	bigest_number = -1;
	while (size > i)
	{
		if (element >= stack[i] && tmp <= stack[i])
		{
			bigest_number = i;
			tmp = stack[i];
		}
		i++;
	}
	i = 0;
	if (bigest_number == -1)
	{
		while (size > i)
		{
			if (tmp > stack[i])
			{
				bigest_number = i;
				tmp = stack[i];
			}
			i++;
		}
	}
	return bigest_number;
}
int main()
{
	int stack_a[6] = {6, 8, 2, 3, 5};
	printf("%d \n",count_pos_in_stack_a(1, stack_a, 5));
}
