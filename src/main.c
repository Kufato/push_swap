/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:53:01 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:22 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tab_str;
	int		*tab_int;
	int		nbr_arg;

	stack_a = NULL;
	stack_b = NULL;
	nbr_arg = 0;
	check_arguments(join_arguments(argc, argv));
	tab_str = ft_split(join_arguments(argc, argv), ' ');
	nbr_arg = count_arg(tab_str);
	tab_int = put_tab_int(nbr_arg, tab_str);
	check_dup(nbr_arg, tab_int);
	create_stack_a(&stack_a, nbr_arg, tab_int);
	check_order(stack_a);
	if (nbr_arg >= 2 && nbr_arg <= 5)
		choose_small_move(&stack_a, &stack_b, nbr_arg);
	else
		radix_algo(&stack_a, &stack_b, nbr_arg);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
