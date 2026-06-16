# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/13 14:07:47 by thfernan          #+#    #+#              #
#    Updated: 2026/06/16 16:27:38 by thfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I includes -pthread

#=================================================================#
#                           philo sources                         #
#=================================================================#

SRCS	= 	main.c \
			philosophers.c \
			init_simulation.c \
			free_destroy.c \
			ft_atol.c \

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

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

val: $(NAME)
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--trace-children=yes \
		--track-fds=yes \
		./$(NAME) 5 800 200 200

helgrind: $(NAME)
		valgrind \
		--tool=helgrind \
		./$(NAME) 5 800 200 200

sanitize: CFLAGS += -fsanitize=thread
sanitize: re
	@echo "$(BLUE)Compiled with ThreadSanitizer$(RESET)"
	./$(NAME) 5 800 200 200

%.o: %.c
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

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

.PHONY: all bonus clean fclean re val helgrind sanitize unit-tests