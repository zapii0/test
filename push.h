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
	int	maxa;
	int	mina;
	int	mb;
	int	ma;
	int	cheapest;
} t_stack;

t_stack	*converter(char **av);
void	free_stacks(t_stack *stacks);
int		find_index_a(t_stack *stacks, int wanted);
int		ft_minmax(char *nbr);
void	*ft_clean(char **list);
int		numbercounter(char **av);
int		issorted(t_stack *stacks);
int 	error_finder(char **av);
int		target_a(t_stack *stacks);
int		duplicate_finder(t_stack *stacks);
void    push_a(t_stack *stacks);
void	polish_stack_a(t_stack *stacks);
void	sort_three(t_stack *stacks);
int		find_max(int *stack, int len);
void	cost_optimizer(t_stack *stacks, int ma, int mb, int index);
void	cost_calculator(t_stack *stacks, int index, int flag);
int		find_min_index(t_stack *stack, int len);
void	sort_stacks(t_stack *stacks);
void	rotate(t_stack *stacks, int ma, int mb);
int		ft_atol(const char *nptr);
void	polish_stacks(t_stack *stacks, int ma, int mb);
int		find_min(int *stack, int len);
int		find_index_b(t_stack *stacks, int wanted);
int		find_index(t_stack *stacks);
int		ft_isdigitboosted(char *str);
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);
void	rb(t_stack *stacks, int flag);
void	rra(t_stack *stacks, int flag);
void	rrb(t_stack *stacks, int flag);
void	ra(t_stack *stacks, int flag);
void	rrr(t_stack *stacks);
void	pb(t_stack *stacks);
void	pa(t_stack *stacks);
void	rr(t_stack *stacks);
#endif