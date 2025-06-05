/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:44:11 by mirifern          #+#    #+#             */
/*   Updated: 2024/04/26 22:49:24 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	len = ft_lstsize(*stack);
	if (len > 1)
	{
		tmp = *stack;
		*stack = tmp->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		return (true);
	}
	return (false);
}

void	sa(t_stack **stack)
{
	if (*stack)
	{
		if (swap(stack))
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack **stack)
{
	if (*stack)
	{
		if (swap(stack))
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		if (swap(a) && swap(b))
			write(1, "ss\n", 3);
	}
}
