/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:37:41 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:38 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	choose_small_move(t_stack **stack_a, t_stack **stack_b, int nbr_arg)
{
	(void)stack_b;
	if (nbr_arg == 2)
		sort_two(stack_a);
	else if (nbr_arg == 3)
		sort_three(stack_a);
	else if (nbr_arg == 4)
		sort_four(stack_a, stack_b);
	else if (nbr_arg == 5)
		sort_five(stack_a, stack_b);
	return ;
}

void	sort_two(t_stack **stack_a)
{
	move_swap(stack_a, 'a');
	return ;
}

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->index - 1 == (*stack_a)->next->index
		|| (*stack_a)->index + 2 == (*stack_a)->next->index)
		move_swap(stack_a, 'a');
	if ((*stack_a)->index + 1 == (*stack_a)->next->index
		&& (*stack_a)->next->next->index + 1 == (*stack_a)->index)
		move_rev_rotate(stack_a, 'a');
	else if ((*stack_a)->index - 2 == (*stack_a)->next->index)
		move_rotate(stack_a, 'a');
	return ;
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	while (!(*stack_b))
	{
		if ((*stack_a)->index == 0)
			move_push(stack_a, stack_b, 'b');
		else
			move_rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	move_push(stack_b, stack_a, 'a');
	return ;
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (!(*stack_b) || !(*stack_b)->next)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			move_push(stack_a, stack_b, 'b');
		else
			move_rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	if ((*stack_b)->index == 0)
		move_swap(stack_b, 'b');
	move_push(stack_b, stack_a, 'a');
	move_push(stack_b, stack_a, 'a');
	return ;
}
