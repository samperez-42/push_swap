/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:16 by samperez          #+#    #+#             */
/*   Updated: 2024/12/10 17:29:32 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Frees the argv in case it is dynamically allocated
void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

// Frees the stack
void	*free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack)
		return (NULL);
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// Checks non numeric characters
int	error_syntax(char	*argv)
{
	int		i;

	i = 0;
	if (argv[0] == '-')
	{
		i++;
	}
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

// Checks repeating values
int	error_repetition(t_stack_node **a, int nbr)
{
	t_stack_node	*current;

	if (!a)
		return (0);
	current = *a;
	while (current)
	{
		if (nbr == current->nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

// Frees the stack (and the argv in case it's allocated)
void	error_free(t_stack_node **a, char **argv, bool argc_2)
{
	free_stack(a);
	if (argc_2 == true)
		free_argv(argv);
}
