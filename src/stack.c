/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:10:56 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:41 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack_a(t_stack **stack_a, int nbr_arg, int *tab_int)
{
	int		i;

	i = 0;
	while (i < nbr_arg)
	{
		create_node(stack_a, get_index(nbr_arg, tab_int, tab_int[i]));
		i++;
	}
	free(tab_int);
	return ;
}

void	create_node(t_stack **head, int index)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->index = index;
	if (!*head)
	{
		*head = new;
		(*head)->next = NULL;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	check_order(t_stack *stack)
{
	t_stack	*tmp_head;

	tmp_head = stack;
	while (stack->next != NULL)
	{
		if (stack->index < stack->next->index)
			stack = stack->next;
		else
			return ;
	}
	stack = tmp_head;
	free_lst(&stack);
	exit(1);
}
