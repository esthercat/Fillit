# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 16:23:09 by esmoreau          #+#    #+#              #
#    Updated: 2019/03/01 18:40:39 by mamisdra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fillit
SRC 	= ./srcs/main.c ./srcs/parser.c ./srcs/readv2.c ./srcs/algo.c \
		./srcs/algo2.c ./srcs/algo3.c ./srcs/up_left.c
FLAGS 	= -Werror -Wall -Wextra
CC 		= gcc

OBJ = $(SRC:.c=.o)
	CL=\x1b[35m
	GREEN=\033[1;32m
	RED=\033[1;31m
	CL2=\x1b[36m
	NC=\033[0m

all: $(NAME)

%.o: %.c
		@$(CC) -c $< -o $@ $(FLAGS)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft
	@echo "$(GREEN)[✓]$(NC)$(CL) executable $(NAME) built$(NC)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@make -C libft/ fclean
	@rm -rf fillit
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned$(NC)"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
