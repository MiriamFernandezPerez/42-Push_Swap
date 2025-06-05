/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:41:22 by mirifern          #+#    #+#             */
/*   Updated: 2024/04/26 22:52:13 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
		return (true);
	}
	return (false);
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b)
	{
		if (push(a, b))
			write (1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a)
	{
		if (push(b, a))
			write (1, "pb\n", 3);
	}
}
