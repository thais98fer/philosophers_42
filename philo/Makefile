# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/13 14:07:47 by thfernan          #+#    #+#              #
#    Updated: 2026/06/17 17:36:02 by thfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I includes -pthread

#=================================================================#
#                           philo sources                         #
#=================================================================#

SRCS	= 	main.c \
			parse.c \
			init_simulation.c \
			free_destroy.c \
			ft_atol.c \
			routine.c \
			monitor.c \
			time.c \

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
	@echo "$(BLUE)Compiled with -Wall -Werror -Wextra -g3 -I includes -pthread $(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

val: $(NAME)
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--trace-children=yes \
		--track-fds=yes \
		./$(NAME) 5 800 200 200 3

helgrind: $(NAME)
		valgrind \
		--tool=helgrind \
		./$(NAME) 5 1000000 200 200

sanitize: CFLAGS += -fsanitize=thread
sanitize: re
	@echo "$(BLUE)Compiled with ThreadSanitizer$(RESET)"
	./$(NAME) 5 800 200 200 3

%.o: %.c
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

unit-tests:
	@$(MAKE) -C ./tests

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f *.o
	@$(MAKE) --no-print-directory clean -C ./tests

fclean: clean
	@echo "$(RED) -> Philo removed$(RESET)"
	@rm -f $(NAME) $(BONUS)
	@rm -rf ./test/test_report.log
	@$(MAKE) --no-print-directory fclean -C ./tests

re: fclean all

.PHONY: all bonus clean fclean re val helgrind sanitize unit-tests