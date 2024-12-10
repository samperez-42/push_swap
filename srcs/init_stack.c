/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:21:23 by samperez          #+#    #+#             */
/*   Updated: 2024/12/10 17:25:24 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Implement atol
void	init_stack(t_stack_node **a, char **argv, bool argc_2)
{
	long	nbr;
	int		i;

	nbr = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_2);
		nbr = atol(argv[i]); // Need to implement atol
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_2);
		if (error_repetition(a, (int)nbr))
			error_free(a, argv, argc_2);
		append_node(a, argv[i]);
		++i;
	}
}
