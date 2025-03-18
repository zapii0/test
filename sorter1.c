#include "push.h"
#include "libft.h"

void	sort_three(t_stack *stacks)
{
	int	max;

	if (issorted(stacks) == 1)
		return ;
	max = find_max(stacks->stack_a, stacks->lenA);
	if (stacks->stack_a[2] == max)
	{
		sa(stacks);
		return ;
	}
	else if (stacks->stack_a[0] == max)
	{
		ra(stacks, 0);
		if (issorted(stacks) == 1)
			return ;
		sa(stacks);
	}
	else
	{
		rra(stacks, 0);
		if (issorted(stacks) == 1)
			return ;
		sa(stacks);
	}
}

int	find_max(int *stack, int len)
{
	int	i;
	int	max;

	max = stack[0];
	i = 1;
	while (i < len)
	{
		if (stack[i] > max)
			max = stack[i];
		++i;
	}
	return (max);
}

int	find_min(int *stack, int len)
{
	int	min;
	int	i;

	min = stack[0];
	i = 1;
	while (i < len)
	{
		if (stack[i] < min)
			min = stack[i];
		++i;
	}
	return (min);
}

void	target_finder(t_stack *stacks, int index)
{
	int	i;
	int tmp;

	i = 0;
	if (stacks->stack_a[index] < stacks->minb || stacks->stack_a[index] > stacks->maxb)
	{
		stacks->target[index] = find_max(stacks->stack_b, stacks->lenB);
		return ;
	}
	tmp = INT_MIN;
	while (i < stacks->lenB)
	{
		if (stacks->stack_a[index] > stacks->stack_b[i] && tmp < stacks->stack_b[i])
		{
			tmp = stacks->stack_b[i];
		}
		++i;
	}
	stacks->target[index] = tmp;
}

void	sort_stacks(t_stack *stacks)
{
	int	index;

	pb(stacks);
	pb(stacks);
	index = 0;
	while (stacks->lenA > 3)
	{
		stacks->maxb = find_max(stacks->stack_b, stacks->lenB);
		stacks->minb = find_min(stacks->stack_b, stacks->lenB);
		index = 0;
		while (index < stacks->lenA)
		{
		
			target_finder(stacks, index);
			cost_calculator(stacks, index, 0);
			if (stacks->cost[index] <= 1)
				break ;
			index++;
		}
		stacks->cheapest = find_index(stacks);
		target_finder(stacks, stacks->cheapest);
		cost_calculator(stacks, stacks->cheapest, 1);
		pb(stacks);
	}
	sort_three(stacks);
}
