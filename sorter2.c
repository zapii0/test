#include "libft.h"
#include "push.h"

void	cost_calculator(t_stack *stacks, int index, int flag)
{
	int	ma;
	int mb;

	if (index > (stacks->lenA) / 2)
	{
		ma = (stacks->lenA - index);
		ma *= -1;
	}
	else
		ma = index;
	if (find_index_b(stacks, stacks->target[index]) > (stacks->lenB) / 2)
	{	
		mb = (stacks->lenB - find_index_b(stacks, stacks->target[index])); 
		mb *= -1;
	}
	else
	{
		mb = find_index_b(stacks, stacks->target[index]);
	}
	if (flag == 0)
	{
		cost_optimizer(stacks, ma, mb, index);
		return ;
	}
rotate(stacks, ma, mb);
}


void	cost_optimizer(t_stack *stacks, int ma, int mb, int index)
{
	if (ma <= 0 && mb <= 0)
	{
		if (ma > mb)
			stacks->cost[index] = mb * -1;
		else
			stacks->cost[index] = ma * -1;
		return ;
	}
	else if (mb >= 0 && ma >= 0)
	{
		if (ma < mb)
			stacks->cost[index] = mb;
		else
			stacks->cost[index] = ma;
		return ;
	}
	else if (ma < 0 && mb > 0)
	{
		stacks->cost[index] = mb + (ma * -1);
		return ;
	}
	stacks->cost[index] = ma + (mb * -1);
}

void	polish_stacks(t_stack *stacks, int ma, int mb)
{
	if (mb > 0)
		while (mb--)
			rb(stacks, 0);
	else if (mb < 0)
		while (mb++)
			rrb(stacks, 0);
	if (ma > 0)
		while (ma--)
			ra(stacks, 0);
	else if (ma < 0)
		while (ma++)
			rra(stacks, 0);
}

int	find_min_index(t_stack *stacks, int len)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < len)
	{
		if (stacks->cost[i] < min)
			min = stacks->cost[i];
		i++;
	}
	return (i);
}

void	rotate(t_stack *stacks, int ma, int mb)
{
	while (mb > 0 && ma > 0)
	{
		rr(stacks);
		mb--;
		ma--;
	}
	while (mb < 0 && ma < 0)
	{
		rrr(stacks);
		mb++;
		ma++;
	}
	polish_stacks(stacks, ma, mb);
}

int	find_index(t_stack *stacks)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < stacks->lenA)
	{
		if (stacks->cost[i] < stacks->cost[tmp])
			tmp = i;
		i++;
	}
	return (tmp);
}

int find_index_b(t_stack *stacks, int wanted)
{
    int i;

    i = 0;
    while (i < stacks->lenB)
    {
        if (stacks->stack_b[i] == wanted)
            return (i);
        i++;
    }
    return (0);
}

