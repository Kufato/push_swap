/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:07:20 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/13 09:40:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*put_tab_int(int nbr_arg, char **tab_str)
{
	int	*temp_tab;
	int	i;

	temp_tab = malloc(sizeof(int) * nbr_arg);
	if (!temp_tab)
		return (NULL);
	i = 0;
	while (tab_str[i])
	{
		temp_tab[i] = ft_atoi(tab_str[i]);
		if (temp_tab[i] == 0)
		{
			if (check_atoi(tab_str[i], ft_atoi(tab_str[i])) == 1)
			{
				free(temp_tab);
				free_tab_str(tab_str);
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	free_tab_str(tab_str);
	return (temp_tab);
}

int	check_atoi(char *str, int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] != '0' && str[i] != '+' && str[i] != '-')
				return (1);
			i++;
		}
	}
	return (0);
}
