#include "libft.h"
#include "push.h"

int	duplicate_finder(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->lenA - 1)
	{
		j = i + 1;
		while (j < stacks->lenA)
		{
			if (stacks->stack_a[i] == stacks->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int error_finder(char **av)
{
	char	**splited;
	//int		*sa;
	int		i;

	i = 0;
	while (av[i])
	{
		splited = ft_split(av[i], ' ');
		if (!splited || !ft_isdigit(splited[i][0]))
			return (1);
		i++;
	}
	ft_clean(splited);
	return (0);
}

int	ft_atol(const char *nptr)
{
	int		i;	
	long	num;
	int		flag;
	int		m;

	flag = 0;
	num = 0;
	i = 0;
	m = 1;
	while ((nptr[i] < 14 && nptr[i] > 8) || nptr[i] == ' ')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m = m * -1;
		i++;
		flag++;
	}
	while (ft_isdigit(nptr[i]) == 1 && nptr[i])
		num = num * 10 + nptr[i++] - 48;
	if (flag > 1)
		return (0);
	return (num * m);
}