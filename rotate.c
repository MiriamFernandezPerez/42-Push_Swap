/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:42:25 by mirifern          #+#    #+#             */
/*   Updated: 2024/04/26 22:49:57 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stack)
	{
		tmp = *stack;
		last = ft_stacklast(*stack);
		*stack = (*stack)->next;
		last->next = tmp;
		tmp->next = NULL;
		return (true);
	}
	return (false);
}

void	ra(t_stack **stack)
{
	if (*stack)
	{
		if (rotate(stack))
			write (1, "ra\n", 3);
	}
}

void	rb(t_stack **stack)
{
	if (*stack)
	{
		if (rotate(stack))
			write (1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		if (rotate(a) && rotate(b))
			write (1, "rr\n", 3);
	}
}
