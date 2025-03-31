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

int error_finder(char **splited)
{
	int j;

	j = 0;
	while (splited[j])
	{
		if (!ft_isdigitboosted(splited[j]))
			return (0);
		if (!ft_minmax(splited[j]))
			return (0);
		j++;
		}
	return (1);
}
int	ft_minmax(char *nbr)
{
	int	i;

	i = ft_strlen(nbr);
	if (nbr[0] == '-' && i > 11)
		return (0);
	if (i > 10 && nbr[0] != '-')
		return (0);
	if (nbr[0] == '-' && i == 11)
		if (nbr[1] > '2' || nbr[2] > '1' || nbr[3] > '4' || nbr[4] > '7' \
		|| nbr[5] > '4' || nbr[6] > '8' || nbr[7] > '3' || nbr[8] > '6' \
		|| nbr[9] > '4' || nbr[10] > '7')
		return (0);
	if (nbr[0] != '-' && i == 10)
		if (nbr[0] > '2' || nbr[1] > '1' || nbr[2] > '4' || nbr[3] > '7' \
		|| nbr[4] > '4' || nbr[5] > '8' || nbr[6] > '3' || nbr[7] > '6' \
		|| nbr[8] > '4' || nbr[9] > '7')
		return (0);
	return (1);
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

int	ft_isdigitboosted(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1 && str[i + 1])
	{
		i++;
		while (str[i])
		{
			if (ft_isdigit(str[i]))
				i++;
			else
				return (0);
		}
	}
	else
	{
		while (str[i])
		{
			if (ft_isdigit(str[i]))
				i++;
			else
				return (0);
		}
	}
	return (1);
}

