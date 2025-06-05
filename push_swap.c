/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:39:02 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/11 00:20:29 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*nums;
	int	*sorted;

	if (ac == 1)
		return (0);
	check_args(ac, av);
	nums = create_arr_args(ac, av);
	sorted = create_arr_sort(ac - 1, nums);
	create_stacks(ac - 1, nums, sorted);
	free(nums);
	free(sorted);
	return (0);
}
