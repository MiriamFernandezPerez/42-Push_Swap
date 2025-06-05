/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:18:34 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/13 19:51:23 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		return ;
	if ((*stack)->num < (*stack)->next->num)
	{
		if ((*stack)->num < (*stack)->next->next->num)
		{
			rra(stack);
			sa(stack);
		}
		else
			rra(stack);
	}
	if ((*stack)->num > (*stack)->next->num)
	{
		if ((*stack)->num < (*stack)->next->next->num)
			sa(stack);
		else if ((*stack)->next->num < (*stack)->next->next->num)
			ra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
}

void	sort_nums(t_stack **a, t_stack **b, int median)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (ft_lstsize(*a) > 3)
		push_to_b(a, b, median);
	sort_three(a);
	while (*b)
	{
		calculate_current(a);
		calculate_current(b);
		calculate_target(a, b);
		calculate_exit(a, b);
		calculate_cost(a, b);
		make_move_b(b, find_cheaper(b));
		make_move_a(a, (*b)->target);
		pa(a, b);
	}
	calculate_current(a);
	move_smaller(a);
}

void	sort_stacks(t_stack **a, t_stack **b, int median)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else
		sort_nums(a, b, median);
}
/*
void	imprimir_stack(t_stack *stack)
{
	int	i;

	i = 1;
	printf("-----------------------------------\n");
	while (stack)
	{
		printf("%i NUM = %i | index %i ", i, stack->num, stack->index);
		printf(" | current %i | target %i ", stack->current, stack->target);
		printf(" | exit %i | cost %i\n", stack->exit, stack->cost);
		stack = stack->next;
		i++;
	}
}*/
