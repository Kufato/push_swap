/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:47:52 by axcallet          #+#    #+#             */
/*   Updated: 2023/02/09 11:24:46 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ########## Start ##########

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ########## Includes ##########

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

// ########## Structures ##########

typedef struct s_stack
{
	int				index;
	struct s_stack	*next;
}				t_stack;

// ########## Functions ##########

int		check_neg(char *str);
int		check_space(char *str);
int		get_size_binary(int max);
int		count_arg(char **tab_str);
int		arguments_len(char **argv);
int		main(int argc, char **argv);
int		check_atoi(char *str, int nb);
int		get_index(int nbr_arg, int *tab, int nb);
int		*put_tab_int(int nbr_arg, char **tab_char);

char	*join_arguments(int argc, char **argv);

void	free_lst(t_stack **stack);
void	check_arguments(char *str);
void	check_order(t_stack *stack);
void	sort_two(t_stack **stack_a);
void	free_tab_str(char **tab_str);
void	sort_three(t_stack **stack_a);
void	parsing(int argc, char **argv);
void	create_stack_b(t_stack **head);
void	check_dup(int nbr_arg, int *tab);
void	move_swap(t_stack **head, char c);
void	move_rotate(t_stack **head, char c);
void	create_node(t_stack **head, int index);
void	move_rev_rotate(t_stack **head, char c);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	create_stack_a(t_stack **stack_a, int nbr_arg, int *tab_int);
void	radix_algo(t_stack **stack_a, t_stack **stack_b, int nbr_arg);
void	move_push(t_stack **stack_push, t_stack **stack_receive, char c);
void	choose_small_move(t_stack **stack_a, t_stack **stack_b, int nbr_arg);

// ########## End ##########

#endif
