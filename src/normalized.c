/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalized.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:07:15 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:30 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(int nbr_arg, int *tab, int nb)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (j < nbr_arg)
	{
		if (nb > tab[j])
			index++;
		j++;
	}
	return (index);
}
