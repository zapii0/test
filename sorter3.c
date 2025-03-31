#include "libft.h"
#include "push.h"

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

int	target_a(t_stack *stacks)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = INT_MAX;
	while (i < stacks->lenA)
	{
		if (stacks->stack_a[i] > stacks->stack_b[0] && tmp > stacks->stack_a[i])
			tmp = stacks->stack_a[i];
		i++;
	}
	tmp = find_index_a(stacks, tmp);
	return (tmp);
}

void    push_a(t_stack *stacks)
{
    int	index;

	while (stacks->lenB)
	{
		index = target_a(stacks);
		if (index == -1)
			return ;
		if (index <= stacks->lenA / 2)
			while (index-- > 0)
				ra(stacks, 0);
		else
		{
			index = stacks->lenA - index;
			while (index-- > 0)
				rra(stacks, 0);
		}
		pa(stacks);
		stacks->mina = find_min(stacks->stack_a, stacks->lenA);
		stacks->maxa = find_max(stacks->stack_a, stacks->lenA);
	}
	if (!issorted(stacks))
		polish_stack_a(stacks);
}
int find_index_a(t_stack *stacks, int wanted)
{
    int i;

    i = 0;
    while (i < stacks->lenA)
    {
        if (stacks->stack_a[i] == wanted)
            return (i);
        i++;
    }
    return (0);
}
