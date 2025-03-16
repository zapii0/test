#include "libft.h"
#include "push.h"

void 	sa(t_stack *stacks)
{
	int	tmp;

	if (stacks->lenA < 2)
		return ;
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
	ft_printf("%s\n", "sa");
}

void 	sb(t_stack *stacks)
{
	int	tmp;

	if (stacks->lenB < 2)
		return ;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
	ft_printf("%s\n", "sb");
}

void	ss(t_stack *stacks)
{
	if (stacks->lenA < 2 || stacks->lenB < 2)
		return ;
	sa(stacks);
	sb(stacks);
	ft_printf("%s\n", "ss");
}

void	ra(t_stack *stacks)
{
	int	i;
	int tmp;

	i = 0;
	tmp = stacks->stack_a[0];
	while (i < stacks->lenA - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->lenA - 1] = tmp;
	ft_printf("%s\n", "ra");
}

void	rb(t_stack *stacks)
{
	int	i;
	int tmp;

	i = 0;
	tmp = stacks->stack_b[0];
	while (i < stacks->lenB - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->lenB - 1] = tmp;
	ft_printf("%s\n", "rb");
}
