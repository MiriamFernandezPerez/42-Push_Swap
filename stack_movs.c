/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:47:59 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/13 19:52:12 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b, int median)
{
	t_stack	*tmp;
	int		check;

	tmp = *b;
	check = 1;
	if (tmp == NULL)
		check = 0;
	pb(a, b);
	if ((*b)->num > median && check == 1)
		rb(b);
}

void	make_move_a(t_stack **stack, int target)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp->num != target)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;
	while (tmp->num != target)
	{
		tmp = *stack;
		if (tmp->num == target)
			break ;
		if (i <= ft_lstsize(*stack) / 2)
			ra(stack);
		else
			rra(stack);
		calculate_current(&tmp);
		tmp = *stack;
	}
}

void	make_move_b(t_stack **stack, int cost)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->cost == cost)
		{
			while (tmp->current != 0)
			{
				if (tmp->current < ft_lstsize(*stack) / 2)
					rb(stack);
				else
					rrb(stack);
				calculate_current(stack);
			}
			break ;
		}
		tmp = tmp->next;
	}
}

int	find_cheaper(t_stack **stack)
{
	t_stack	*tmp;
	int		cheaper;

	tmp = *stack;
	cheaper = -1;
	while (tmp)
	{
		if (tmp->current == 0)
			cheaper = tmp->cost;
		if (tmp->cost < cheaper)
			cheaper = tmp->cost;
		tmp->cost = cheaper;
		tmp = tmp->next;
	}
	return (cheaper);
}

void	move_smaller(t_stack **stack)
{
	t_stack	*tmp;
	int		smaller;

	tmp = *stack;
	smaller = INT_MAX;
	while (tmp)
	{
		if (tmp->num < smaller)
			smaller = tmp->num;
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp->index != 0)
	{
		tmp = *stack;
		if (tmp->index > ft_lstsize(*stack) / 2)
			ra(stack);
		else
			rra(stack);
		calculate_current(stack);
		if ((*stack)->num == smaller)
			break ;
	}
}
