/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:09:00 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/13 19:43:51 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int num, int *sorted, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (sorted[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack->next)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	ft_lstadd_back(t_stack *stack, t_stack *nodo)
{
	t_stack	*temp;

	temp = ft_stacklast(stack);
	if (!temp)
		stack = nodo;
	else
		temp->next = nodo;
}

t_stack	*create_node(int num, int *sorted, int ac)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
	if (!nodo)
		return (NULL);
	nodo->num = num;
	nodo->index = find_index(num, sorted, ac);
	nodo->current = 0;
	nodo->target = 0;
	nodo->cost = 0;
	nodo->next = NULL;
	return (nodo);
}

void	create_stacks(int ac, int *nums, int *sorted)
{
	int		i;
	int		median;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	a = NULL;
	b = NULL;
	median = sorted[ac / 2];
	if (a == NULL)
	{
		a = create_node(nums[i], sorted, ac);
		i++;
	}
	while (i < ac)
	{
		ft_lstadd_back(a, create_node(nums[i], sorted, ac));
		i++;
	}
	sort_stacks(&a, &b, median);
	free_stack(&a);
	free_stack(&b);
}
