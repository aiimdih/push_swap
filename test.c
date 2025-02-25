#include <stdio.h>


void push_a(int *stack_a, int *stack_b, int *element_a, int *element_b)
{
	int i;
	int prev;
	int tmp_1;

	i = 0;
	prev = stack_a[i + 1];
	stack_a[i + 1] = stack_a[i];
	i++;
	while (i < *element_a)
	{
		tmp_1 = stack_a[i + 1]; 
		stack_a[i + 1] = prev;
		prev = tmp_1;
		i++;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < 4)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	while (i <= *element_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	element_b--;
	element_a++;
	i = 0;
	printf("x\n");
}

int main()
{
	int element_b = 3;
	int element_a = 3;
	int stack_a[3] = {0, 2, 6};
	int stack_b[3] = {3 ,4 ,7};
	push_a(stack_a, stack_b, &element_a, &element_b);
}
