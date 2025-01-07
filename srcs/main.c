/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:50:00 by samperez          #+#    #+#             */
/*   Updated: 2025/01/07 15:19:14 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_ps_split(argv[1], ' ');
	if (!argv)
		return (0);
	init_stack(&a, argv + 1, 2 == argc);
	if (stack_size(a) == 2)
		sort_two(a);
	else if (stack_size(a) == 3)
		sort_three(a);
	free_stack(&a);
}
