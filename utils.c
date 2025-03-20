#include "push.h"
#include "libft.h"

void	free_stacks(t_stack *stacks)
{
	if (stacks)
	{
		if (stacks->stack_a)
			free(stacks->stack_a);
		if (stacks->stack_b)
			free(stacks->stack_b);
		if (stacks->cost)
			free(stacks->cost);
		if (stacks->target)
			free(stacks->target);
		free(stacks);
	}
}

void	*ft_clean(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}
int	numbercounter(char **av)
{
	int	counter;
	int	j;
	char **splitted;
	int	k;

	counter = 0;
	j = 1;
	k = 0;
	while (av[j])
	{
		splitted = ft_split(av[j], ' ');
		if (!splitted)
			return (0);
		while (splitted[k])
		{
			counter++;
			k++;
		}
		if (error_finder(splitted))
			return (ft_clean(splitted), -1);
		ft_clean(splitted);
		k = 0;
		j++;
	}
	return (counter);
}

void	pb(t_stack *stacks)
{
	int	i;

	if (stacks->lenA < 1)
		return ;
	i = stacks->lenB;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->lenB++;
	stacks->lenA--;
	i = 0;
	while (i < stacks->lenA)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->lenA] = 0;
	ft_printf("%s\n", "pb");
}

int	issorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len - 1)
	{
		if (stacks->stack_a[i] < stacks->stack_a[i + 1])
			++i;
		else
			return (0);
	}
	return (1);
}
