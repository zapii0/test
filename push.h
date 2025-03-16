#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>

typedef struct Stack
{
	int	*stack_a;
	int	*stack_b;
	int	len;
	int	lenA;
	int	lenB;
	int	*cost;
	int *target;
	int minb;
	int maxb;
	int	mb;
	int	ma;
	int	cheapest;
} t_stack;

t_stack	*converter(char **av);
void	free_stacks(t_stack *stacks);
void	*ft_clean(char **list);
int		numbercounter(char **av);
int		issorted(t_stack *stacks);
void	sort_three(t_stack *stacks);
int		find_max(int *stack, int len);
void	cost_optimizer(t_stack *stacks, int ma, int mb, int index);
void	cost_calculator(t_stack *stacks, int index, int flag);
int		find_min_index(t_stack *stack, int len);
void	sort_stacks(t_stack *stacks);
void	rotate(t_stack *stacks, int ma, int mb);
void	polish_stacks(t_stack *stacks, int ma, int mb);
int		find_index_b(t_stack *stacks, int wanted);
int		find_index(t_stack *stacks);
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);
void	pb(t_stack *stacks);
void	pa(t_stack *stacks);
void	rr(t_stack *stacks);
#endif