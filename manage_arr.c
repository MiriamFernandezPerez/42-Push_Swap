/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:58:37 by mirifern          #+#    #+#             */
/*   Updated: 2024/04/22 20:52:19 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*cpy_arr(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		b[i] = a[i];
		i++;
	}
	return (b);
}

int	*sort_arr(int len, int *sorted)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < len - 1)
	{
		if (sorted[i] == sorted[i + 1])
			ft_error(1);
		if (sorted[i] > sorted[i + 1])
		{
			ft_swap(&sorted[i], &sorted[i + 1]);
			i = 0;
			check = 1;
		}
		else
			i++;
	}
	if (check == 0)
		exit (0);
	return (sorted);
}

int	*create_arr_sort(int len, int *arr_args)
{
	int	i;
	int	*sorted;

	i = 0;
	sorted = (int *)malloc(sizeof(int *) * len);
	if (sorted == NULL)
	{
		free (sorted);
		exit(0);
	}
	sorted = cpy_arr(arr_args, sorted, len);
	sorted = sort_arr(len, sorted);
	return (sorted);
}

int	*create_arr_args(int ac, char **av)
{
	int	i;
	int	index;
	int	*arr_args;

	i = 1;
	index = 0;
	arr_args = (int *)malloc(sizeof(int) * ac);
	if (arr_args == NULL)
	{
		free(arr_args);
		exit (0);
	}
	while (i < ac)
	{
		arr_args[index] = ft_atoi(av[i]);
		i++;
		index++;
	}
	arr_args[index] = '\0';
	return (arr_args);
}
/*
void	ft_print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%i\n", arr[i]);
		i++;
	}
}*/
