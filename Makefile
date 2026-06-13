# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/13 14:07:47 by thfernan          #+#    #+#              #
#    Updated: 2026/06/13 14:34:24 by thfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I includes

#=================================================================#
#                           philo sources                         #
#=================================================================#

SRCS	= philoshophers.c \
			sample.c \
			

OBJS = $(SRCS:.c=.o)

#=================================================================#
#                               rules                             #
#=================================================================#

# Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

all: $(NAME)
	@echo "$(GREEN)	-> Philo ready $(RESET)"

val:
	valgrind \
		--leak-check=full \
		--show-leak-kind=all \
		--track-origins=yes \
		--trace-children=yes \
		--track-fds=yes \
		./$(NAME)

%.o: %.c
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

unit-tests:
	@$(MAKE) -C ./tests

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f *.o
	@$(MAKE) clean -C ./tests

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME) $(BONUS)
	@rm -rf ./test/test_report.log
	@$(MAKE) fclean -C ./tests

re: fclean all

.PHONY: all bonus clean fclean re