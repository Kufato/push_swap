/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:44:12 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:34 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_algo(t_stack **stack_a, t_stack **stack_b, int nbr_arg)
{
	int	bit;
	int	i;
	int	j;

	bit = get_size_binary(nbr_arg - 1);
	i = 0;
	while (i < bit)
	{
		j = 0;
		while (j < nbr_arg)
		{
			if (!((*stack_a)->index >> i & 1))
				move_push(stack_a, stack_b, 'b');
			else
				move_rotate(stack_a, 'a');
			j++;
		}
		while (*stack_b)
			move_push(stack_b, stack_a, 'a');
		i++;
	}
}

int	get_size_binary(int max)
{
	int	binary;

	binary = 0;
	while (max)
	{
		max /= 2;
		binary++;
	}
	return (binary);
}
