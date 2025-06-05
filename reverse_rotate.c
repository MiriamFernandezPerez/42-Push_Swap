/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:43:20 by mirifern          #+#    #+#             */
/*   Updated: 2024/04/26 22:50:26 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (stack)
	{
		i = 0;
		tmp = *stack;
		while ((*stack)->next)
		{
			*stack = (*stack)->next;
			i++;
		}
		(*stack)->next = tmp;
		while (i > 1)
		{
			tmp = tmp->next;
			i--;
		}
		tmp->next = NULL;
		return (true);
	}
	return (false);
}

void	rra(t_stack **stack)
{
	if (*stack)
	{
		if (reverse_rotate(stack))
			write (1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack)
{
	if (*stack)
	{
		if (reverse_rotate(stack))
			write (1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		if (reverse_rotate(a) && reverse_rotate(b))
			write (1, "rrr\n", 4);
	}
}
