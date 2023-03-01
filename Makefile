# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 11:48:31 by axcallet          #+#    #+#              #
#    Updated: 2023/02/09 13:30:15 by axcallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########### ARGUMENTS ##########

NAME		= push_swap
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g

########## SOURCES ##########

SRCS		= src/arguments.c		\
			src/check_inputs.c		\
			src/free.c				\
			src/main.c				\
			src/movements.c			\
			src/normalized.c		\
			src/radix.c				\
			src/small_movements.c	\
			src/stack.c				\
			src/utils.c

OBJS		= $(SRCS:.c=.o)
LIBFT		= libft

########## RULES ##########

RM			= rm -f

all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) lib
		@$(CC) $(CFLAGS) -L $(LIBFT) -o $(NAME) $(OBJS) -l:libft.a

lib:
	@$(MAKE) -s -C $(LIBFT) bonus

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean

re: fclean $(NAME)

.PHONY: all lib clean fclean re create_progressbar
