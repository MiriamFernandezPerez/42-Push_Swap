/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:54:45 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/13 19:43:25 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int n)
{
	if (n == 1)
	{
		write(2, "Error", 5);
		exit(0);
	}
}

void	check_limits(char *s)
{
	int		len;
	char	*max;
	char	*min;

	len = ft_strlen(s);
	max = "2147483647";
	min = "-2147483648";
	if (len == 11)
	{
		if (ft_strcmp(s, min) > 0)
			ft_error(1);
	}
	if (len == 10)
	{
		if (ft_strcmp(s, max) > 0)
			ft_error(1);
	}
	if (len > 11)
		ft_error(1);
}

void	check_int(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '-' && (av[1] >= '0' && av[1] <= '9'))
		i++;
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
			i++;
		else
			ft_error(1);
	}
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			ft_error(1);
		check_int(av[i]);
		check_limits(av[i]);
		i++;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
