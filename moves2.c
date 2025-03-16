/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:25:50 by mzapora           #+#    #+#             */
/*   Updated: 2025/03/11 00:15:11 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push.h"

void    rr(t_stack *stacks)
{
    if (stacks->lenA < 2 || stacks->lenB < 2)
        return ;
    ra(stacks);
    rb(stacks);
	ft_printf("%s\n", "rr");
}
void	rra(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->lenA < 2)
		return ;
	i = stacks->lenA - 1;
	tmp = stacks->stack_a[stacks->lenA - 1];
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = tmp;
	ft_printf("%s\n", "rra");
}

void	rrb(t_stack *stacks)
{
	int	i;
	int	tmp;

	if (stacks->lenB < 2)
		return ;
	i = stacks->lenB - 1;
	tmp = stacks->stack_b[stacks->lenB - 1];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = tmp;
	ft_printf("%s\n", "rrb");
}

void	rrr(t_stack *stacks)
{
	if (stacks->lenA < 2 || stacks->lenB < 2)
		return ;
	rra(stacks);
	rrb(stacks);
	ft_printf("%s\n", "rrr");
}

void	pa(t_stack *stacks)
{
	int	i;

	if (stacks->lenB < 1)
		return ;
	i = stacks->lenA;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->lenA++;
	stacks->lenB--;
	i = 0;
	while (i < stacks->lenB)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->lenB] = 0;
	ft_printf("%s\n", "pa");
}


