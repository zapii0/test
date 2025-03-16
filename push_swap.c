#include "libft.h"
#include "push.h"

int *stack_creator(char **av, int *sa)
{
	int		j;
	int		i;
	int		k;
	char	**splited;

	j = 1;
	k = 0;
	i = 0;
	while (av[j])
	{
		splited = ft_split(av[j], ' ');
		if (!splited)
			return (NULL);
		while (splited[k])
		{
			sa[i] = ft_atoi(splited[k]);
			++k;
			++i;
		}
		k = 0;
		ft_clean(splited);
		++j;
	}
	return (sa);
}

t_stack	*converter(char **av)
{
	t_stack	*stacks;
	int	j;

	if (!(stacks = malloc(sizeof(t_stack))))
		return (NULL);
	j = numbercounter(av);
	stacks->stack_a = malloc(sizeof(int) * j);
	stacks->stack_b = malloc(sizeof(int) * j);
	stacks->cost = malloc(sizeof(int) * j);
	stacks->target = malloc(sizeof(int) * j);
	stacks->len = j;
	if (!stacks->stack_a || !stacks->stack_b || !stacks->cost || \
	!stacks->target)
		return (free_stacks(stacks), NULL);
	stacks->stack_a = stack_creator(av, stacks->stack_a);
	return (stacks);
}

void	pushswap(t_stack *stacks)
{
	if (stacks->len == 1)
		return ;
	if (stacks->len == 2)
	{
		if (issorted(stacks) == 1)
			return ;
		sa(stacks);
		return ;
	}
	if (stacks->len == 3)
	{
		sort_three(stacks);
	}
	if (stacks->len > 3 && !issorted(stacks))
	{
		sort_stacks(stacks);
	}
}
int main(int ac, char **av)
{
	t_stack *stacks;

	if (ac == 1)
		return (0);
	stacks = converter(av);
	stacks->lenB = 0;
	stacks->lenA = stacks->len;
	//int	i = 0;
	pushswap(stacks);
	/*while (i < stacks->len)
	{
		printf("%d\n", stacks->stack_b[i]);
		i++;
	}*/
	return (free_stacks(stacks), 0);
}
