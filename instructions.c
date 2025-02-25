#include "push_swap.h"

void swap(int *stack)
{
	int *tmp;

	tmp = stack[1];
	stack[1] = stack[0];
	stack[0] = tmp;
}

void swap_a(t_utils utils)
{
	if (utils->element < 2)
		return;
	swap(utils->stack_a);
}

void swap_b(t_utils utils)
{
	if (utils->element < 2)
		return;
	swap(utils->stack_b);
}

void swap_a_and_b(t_utils utils)
{
	swap(utils->stack_a);
	rwap(utils->stack_b);
}

void push_a(t_utils utils)
{
	int i;
	int prev;
	int tmp_1;

	i = 0;
	prev = utils->stack_a[i + 1];
	utils->stack_a[i + 1] = utils->stack_a[i];
	i++;
	while (i < utils->element)
	{
		tmp_1 = utils->stack_a[i + 1] 
		utils->stack_a[i + 1] = prev;
		prev = tmp_1;
	}
	utils->stack_a[0] = utils->stack_b[0];
	i = 0;
	while (i <= utils->element_b)
	{
		utils->stack_b[i] = utils->stack_b[i + 1];
		i++;
	}
	utils->element_b--;
	utils->element_a++;
}

void push_b(t_utils utils)
{
	int i;
	int prev;
	int tmp_1;

	i = 0;
	prev = utils->stack_b[i + 1];
	utils->stack_b[i + 1] = utils->stack_b[i];
	i++;
	while (i < utils->element)
	{
		tmp_1 = utils->stack_b[i + 1] 
		utils->stack_b[i + 1] = prev;
		prev = tmp_1;
	}
	utils->stack_b[0] = utils->stack_a[0];
	i = 0;
	while (i <= utils->element_a)
	{
		utils->stack_a[i] = utils->stack_a[i + 1];
		i++;
	}
	utils->element_a--;
	utils->element_b++;
}

void rotate_a(t_utils utils)
{
	int i;
	int tmp;


}

void rotate_b(t_utils utils)
{
}

void rotate_a_and_b(t_utils utils)
{

}

void reverse_rotate_a(t_utils utils)
{

}

void reverse_rotate_b(t_utils utils)
{

}

void reverse_rotate_a_b(t_utils utils)
{

}
