/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:48:41 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/13 19:53:38 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smaller(t_stack **stack)
{
	t_stack	*tmp;
	int		small;

	tmp = *stack;
	small = INT_MAX;
	while (tmp)
	{
		if (tmp->num < small)
			small = tmp->num;
		tmp = tmp->next;
	}
	return (small);
}

void	calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_b->target == tmp_a->num)
				tmp_b->cost = tmp_a->exit + tmp_b->exit;
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void	calculate_exit(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*t_b;

	tmp_a = *a;
	t_b = *b;
	while (tmp_a)
	{
		if (tmp_a->current > ft_lstsize(*a) / 2)
			tmp_a->exit = (((ft_lstsize(*a) * -1) + tmp_a->current) * -1);
		else
			tmp_a->exit = tmp_a->current;
		tmp_a = tmp_a->next;
	}
	while (t_b)
	{
		if (t_b->current > ft_lstsize(*b) / 2)
			t_b->exit = (((ft_lstsize(*b) * -1) + t_b->current) * -1) + 1;
		else
			t_b->exit = t_b->current + 1;
		t_b = t_b->next;
	}
}

void	calculate_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		target;
	int		check;

	tmp_b = *b;
	while (tmp_b)
	{
		check = 0;
		tmp_a = *a;
		target = INT_MAX;
		while (tmp_a)
		{
			if (tmp_a->num > tmp_b->num && tmp_a->num < target)
			{
				check = 1;
				target = tmp_a->num;
			}
			tmp_a = tmp_a->next;
		}
		if (check == 0)
			target = find_smaller(a);
		tmp_b->target = target;
		tmp_b = tmp_b->next;
	}
}

void	calculate_current(t_stack **stack)
{
	t_stack	*tmp;
	int		index;

	tmp = *stack;
	index = 0;
	while (tmp)
	{
		tmp->current = index;
		index++;
		tmp = tmp->next;
	}
}
