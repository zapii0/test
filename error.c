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
		{
			return (0);
		}
		j++;
	}
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
	if (!str || !str[i]) // Sprawdzenie, czy `str` nie jest puste
		return (0);
	if (str[i] == '-') // Obsługa liczby ujemnej
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0); // Jeśli znajdzie niecyfrowy znak, zwraca 0 (fałsz)
		i++;
	}
	return (1); // Zwraca 1 (prawda), jeśli string zawiera tylko cyfry
}

