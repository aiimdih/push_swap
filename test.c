#include <stdio.h>

int count_pos_in_stack_a(int element, int *stack, int size)
{
	int count;
	int i;
	int bigest_number;
	int tmp;

	i = 0;
	bigest_number = 0;
	bigest_number = -1;
	tmp = stack[i];
	while (size > i)
	{
		if (element > stack[i])
		{
			tmp = stack[i];
			break;
		}
		i++;
	}
	i = 0;
	while (size > i)
	{
		printf("element===> %d, stack[i] %d tmp ==> %d\n", element, stack[i], tmp);
		if (element >= stack[i] && tmp <= stack[i])
		{
			bigest_number = i;
			tmp = stack[i];
		}
		i++;
	} 
	printf("%d\n", tmp);
	i = 0;
	if (bigest_number == -1)
	{
		while (size > i)
		{
			printf("element===> %d, stack[i] %d tmp ==> %d\n", element, stack[i], tmp);
			if (stack[i] > element && tmp >= stack[i])
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
	int stack_a[9] = {28, 29, 5, 7, 11, 12, 20, 21, 27};
	printf("%d \n",count_pos_in_stack_a(4, stack_a, 9));
}
