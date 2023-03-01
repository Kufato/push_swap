/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:13:09 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 15:07:14 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*join_arguments(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	if (argc == 1)
		exit(1);
	str = malloc(sizeof(char) * (arguments_len(argv) + argc - 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i != argc)
	{
		if (argv[i][0] == '\0')
		{
			write(1, "Error\n", 6);
			free(str);
			exit(1);
		}
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	return (str);
}

int	arguments_len(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	j = 0;
	len = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			len++;
			j++;
		}
		i++;
		j = 0;
	}
	return (len);
}

int	count_arg(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
		i++;
	return (i);
}
