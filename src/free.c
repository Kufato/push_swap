/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:52:43 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:18 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_lst(t_stack **stack)
{
	if ((*stack) != NULL)
	{
		free_lst(&(*stack)->next);
		free((*stack));
	}
}

void	free_tab_str(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
}
