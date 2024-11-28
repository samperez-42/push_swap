/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:47:59 by samperez          #+#    #+#             */
/*   Updated: 2024/11/28 17:32:38 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*last;
	int				len;

	len = stack_size(*head);
	if (!head || !*head || len == 1)
		return ;
	last = find_last_node(*head);
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	last->next->prev = last;
}

void	rra(t_stack_node *a, bool *checker)
{
	rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node *b, bool *checker)
{
	rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node *a, t_stack_node *b, bool *checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
