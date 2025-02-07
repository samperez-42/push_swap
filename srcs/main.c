/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:50:00 by samperez          #+#    #+#             */
/*   Updated: 2025/02/07 13:49:51 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Erase after finishing */
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("\nNumber in stack a: %d\nBelow:%s\nTarget node: %d\nTotal Push Cost: %d\n", stack->nbr, stack->below ? "true" : "false", stack->target_node->nbr, stack->push_cost);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_ps_split(argv[1], ' ');
	if (!argv)
		return (0);
	init_stack(&a, argv + 1, 2 == argc);
	pb(&b, &a);/**/
	pb(&b, &a);/**/
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
}
