#include <stdio.h>

/*int count_pos_in_stack_a(int element, int *stack, int size)*/
/*{*/
/*	int count;*/
/*	int i;*/
/*	int bigest_number;*/
/*	int tmp;*/
/**/
/*	i = 0;*/
/*	bigest_number = 0;*/
/*	bigest_number = -1;*/
/*	tmp = stack[i];*/
/*	while (size > i)*/
/*	{*/
/*		if (element > stack[i])*/
/*		{*/
/*			tmp = stack[i];*/
/*			break;*/
/*		}*/
/*		i++;*/
/*	}*/
/*	i = 0;*/
/*	while (size > i)*/
/*	{*/
/*		printf("element===> %d, stack[i] %d tmp ==> %d\n", element, stack[i], tmp);*/
/*		if (element >= stack[i] && tmp <= stack[i])*/
/*		{*/
/*			bigest_number = i + 1;*/
/*			tmp = stack[i];*/
/*		}*/
/*		i++;*/
/*	} */
/*	printf("%d\n", tmp);*/
/*	i = 0;*/
/*	if (bigest_number == -1)*/
/*	{*/
/*		while (size > i)*/
/*		{*/
/*			printf("element===> %d, stack[i] %d tmp ==> %d\n", element, stack[i], tmp);*/
/*			if (stack[i] > element && tmp >= stack[i])*/
/*			{*/
/*				bigest_number = i;*/
/*				tmp = stack[i];*/
/*			}*/
/*			i++;*/
/*		}*/
/*	}*/
/*	return bigest_number;*/
/*}*/
int find_bigger(int *stack, int size)
{
	int tmp;
	int i;
	int j;
	int index;
	
	tmp = stack[0]; 
	i = 0;
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
int main()
{
	int stack_a[4] = {40, 50, 16, 6};
	printf("%d \n", find_bigger(stack_a, 4));
}
