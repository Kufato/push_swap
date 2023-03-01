/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:22:50 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:26 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_swap(t_stack **head, char c)
{
	t_stack	*tmp;

	if ((*head)->next != NULL)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	move_push(t_stack **stack_push, t_stack **stack_receive, char c)
{
	t_stack	*tmp;

	if (!stack_push)
		return ;
	tmp = (*stack_push);
	(*stack_push) = (*stack_push)->next;
	tmp->next = (*stack_receive);
	(*stack_receive) = tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	move_rotate(t_stack **head, char c)
{
	t_stack	*tmp_head;
	t_stack	*tmp;

	if ((*head)->next != NULL)
	{
		tmp_head = (*head);
		tmp = (*head);
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*head) = (*head)->next;
		tmp->next = tmp_head;
		tmp_head->next = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	move_rev_rotate(t_stack **head, char c)
{
	t_stack	*tmp_last;
	t_stack	*tmp_prev;

	if ((*head)->next != NULL)
	{
		tmp_last = (*head)->next;
		tmp_prev = (*head);
		while (tmp_last->next != NULL)
		{
			tmp_prev = tmp_last;
			tmp_last = tmp_last->next;
		}
		tmp_last->next = (*head);
		tmp_prev->next = NULL;
		(*head) = tmp_last;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
