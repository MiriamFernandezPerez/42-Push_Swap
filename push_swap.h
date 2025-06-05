/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:41:17 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/10 21:53:19 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				current;
	int				target;
	int				exit;
	int				cost;
	struct s_stack	*next;
}	t_stack;
//check_args
void	ft_error(int c);
void	check_limits(char *s);
void	check_int(char *av);
int		check_args(int ac, char **av);
void	free_stack(t_stack **stack);
//utils
void	ft_putstr(char *s);
int		ft_strlen(char *s);
int		ft_atoi(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_lstsize(t_stack *stack);
//manage_arr
void	ft_swap(int *a, int *b);
int		*cpy_arr(int *a, int *b, int len);
int		*sort_arr(int len, int *sorted);
int		*create_arr_sort(int i, int *arr_args);
int		*create_arr_args(int ac, char **av);
void	ft_print_arr(int *arr, int len); //quit comment to use
//manage_stacks
int		find_index(int num, int *sorted, int ac);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_lstadd_back(t_stack *stack, t_stack *nodo);
t_stack	*create_node(int num, int *sorted, int ac);
void	create_stacks(int ac, int *nums, int *sorted);
//swap
bool	swap(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
//push
bool	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//rotate
bool	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
//reverse_rotate
bool	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
//sort_stacks
void	sort_three(t_stack	**stack);
void	sort_nums(t_stack **a, t_stack **b, int median);
void	sort_stacks(t_stack **a, t_stack **b, int median);
void	imprimir_stack(t_stack *stack); //quit comment to use
//stack_props
int		find_smaller(t_stack **stack);
void	calculate_cost(t_stack **a, t_stack **b);
void	calculate_exit(t_stack **a, t_stack **b);
void	calculate_target(t_stack **a, t_stack **b);
void	calculate_current(t_stack **stack);
//stack_movs
void	push_to_b(t_stack	**a, t_stack **b, int median);
void	make_move_a(t_stack **stack, int target);
void	make_move_b(t_stack **stack, int cost);
int		find_cheaper(t_stack **stack);
void	move_smaller(t_stack **stack);
#endif
