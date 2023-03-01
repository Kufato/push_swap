/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:29:38 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 15:18:57 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_arguments(char *str)
{
	if (ft_str_isdigit(str) == 1
		|| check_neg(str) == 1
		|| check_space(str) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free(str);
		exit(1);
	}
	free(str);
}

int	check_neg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit((int)str[i]) == 1
			&& str[i + 1] == ' ')
			i++;
		else if ((str[i] == '+' && str[i + 1] == ' ')
			|| (str[i] == '-' && str[i + 1] == ' ')
			|| (str[i] == '+' && i != 0 && ft_isdigit(str[i - 1]))
			|| (str[i] == '-' && i != 0 && ft_isdigit(str[i - 1])))
			return (1);
		else if (str[i] == '-'
			&& ft_isdigit((int)str[i + 1]) == 0)
			return (1);
		else if (str[i] == '+'
			&& ft_isdigit((int)str[i + 1]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	check_dup(int nbr_arg, int *tab_int)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < nbr_arg)
	{
		while (j < nbr_arg)
		{
			if (tab_int[j] == ' ' || tab_int[j] == '+' || tab_int[j] == '-')
				j++;
			else if (tab_int[i] == tab_int[j])
			{
				ft_putstr_fd("Error\n", 2);
				free(tab_int);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '	')
			return (0);
		i++;
	}
	return (1);
}
