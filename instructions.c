#include "push_swap.h"

void swap(int *stack)
{
	int tmp;

	tmp = stack[1];
	stack[1] = stack[0];
	stack[0] = tmp;
}

void swap_a(t_utils *utils)
{
	if (utils->element_a < 2)
		return;
	swap(utils->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void swap_b(t_utils *utils)
{
	if (utils->element_b < 2)
		return;
	swap(utils->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void swap_a_and_b(t_utils *utils)
{
	swap(utils->stack_a);
	swap(utils->stack_b);
	ft_putstr_fd("ss\n", 1);
}

void push_a(t_utils *utils)
{
	int i;
	int prev;
	int tmp_1;

	if (utils->element_b < 1)
		return;
	i = 0;
	prev = utils->stack_a[i + 1];
	utils->stack_a[i + 1] = utils->stack_a[i];
	i++;
	while (i < utils->element_a)
	{
		tmp_1 = utils->stack_a[i + 1];
		utils->stack_a[i + 1] = prev;
		prev = tmp_1;
		i++;
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
	ft_putstr_fd("pa\n", 1);
}

void push_b(t_utils *utils)
{
	int i;
	int prev;
	int tmp_1;

	if (utils->element_a < 1)
		return;
	i = 0;
	prev = utils->stack_b[i + 1];
	utils->stack_b[i + 1] = utils->stack_b[i];
	i++;
	while (i < utils->element_b)
	{
		tmp_1 = utils->stack_b[i + 1]; 
		utils->stack_b[i + 1] = prev;
		prev = tmp_1;
		i++;
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
	ft_putstr_fd("pb\n", 1);
}

void rotate_a(t_utils *utils)
{
	int i;
	int tmp;
	
	tmp = utils->stack_a[0];
	i = 0;
	while (i <= utils->element_a)
	{
		utils->stack_a[i] = utils->stack_a[i + 1];
		i++;
	}
	utils->stack_a[utils->element_a - 1] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void rotate_b(t_utils *utils)
{
	int i;
	int tmp;
	
	tmp = utils->stack_b[0];
	i = 0;
	while (i <= utils->element_b)
	{
		utils->stack_b[i] = utils->stack_b[i + 1];
		i++;
	}
	utils->stack_b[utils->element_b - 1] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void rotate_a_and_b(t_utils *utils)
{
	int i;
	int tmp;
	
	i = 0;
	tmp = utils->stack_a[0];
	while (i <= utils->element_a)
	{
		utils->stack_a[i] = utils->stack_a[i + 1];
		i++;
	}
	utils->stack_a[utils->element_a] = tmp;
	i = 0;
	tmp = utils->stack_b[0];
	while (i <= utils->element_b)
	{
		utils->stack_b[i] = utils->stack_b[i + 1];
		i++;
	}
	utils->stack_b[utils->element_b] = tmp;
	ft_putstr_fd("rr\n", 1);
}

void reverse_rotate_a(t_utils *utils)
{
	int i;
	int tmp;
	
	i = utils->element_a - 1;
	tmp = utils->stack_a[i];	
	while (i > 0)
	{
		utils->stack_a[i] = utils->stack_a[i - 1];
		i--;
	}
	utils->stack_a[0] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void reverse_rotate_b(t_utils *utils)
{
	int i;
	int tmp;
	
	i = utils->element_b - 1;
	tmp = utils->stack_b[i];	
	while (i > 0)
	{
		utils->stack_b[i] = utils->stack_b[i - 1];
		i--;
	}
	utils->stack_b[0] = tmp;
	ft_putstr_fd("rrb\n", 1);

}

void reverse_rotate_a_b(t_utils *utils)
{
	int i;
	int tmp;
	
	i = utils->element_a - 1;
	tmp = utils->stack_a[i];	
	while (i > 0)
	{
		utils->stack_a[i] = utils->stack_a[i - 1];
		i--;
	}
	utils->stack_a[0] = tmp;
	i = utils->element_b - 1;
	tmp = utils->stack_b[i];	
	while (i > 0)
	{
		utils->stack_b[i] = utils->stack_b[i - 1];
		i--;
	}
	utils->stack_b[0] = tmp;
	ft_putstr_fd("rrr\n", 1);
}
