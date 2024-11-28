/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:47:59 by samperez          #+#    #+#             */
/*   Updated: 2024/11/28 17:32:57 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node	*last;
	int				len;

	len = stack_size(*head);
	if (!head || !*head || len == 1)
		return ;
	last = get_last_node(*head);
	last->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node *a, bool *checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node *b, bool *checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node *a, t_stack_node *b, bool *checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
