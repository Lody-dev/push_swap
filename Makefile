# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsarmien <viaremko@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 19:52:12 by viaremko          #+#    #+#              #
#    Updated: 2025/02/27 19:08:06 by viaremko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Instructions
NAME 	= push_swap
LIB		= libft.a
CC 		= gcc
FLAGS 	= -Wall -Wextra -Werror -I $(INC_DIR)
MD		= mkdir -p
RM		= rm -f
PRINT	= echo

# Directories
BLD_DIR = build
INC_DIR = inc
LIB_DIR = lib
OBJ_DIR	= $(BLD_DIR)/obj
SRC_DIR = src

# C Source Files
SRC		= $(SRC_DIR)/stack_a.c $(SRC_DIR)/stack_b.c $(SRC_DIR)/stack_ab.c \
		  $(SRC_DIR)/stack_targeting.c $(SRC_DIR)/stack_costs.c $(SRC_DIR)/stack_rotator.c \
		  $(SRC_DIR)/stack_simple_sorting.c $(SRC_DIR)/stack_complex_sorting.c \
		  $(SRC_DIR)/stack_utils.c $(SRC_DIR)/utils.c \
		  $(SRC_DIR)/input_handling.c $(SRC_DIR)/main.c

# Object Files
OBJ_MAN	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# ANSI Colors
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
RESET	= \033[0m

# Compiler Rules

$(LIB_DIR)/$(LIB):
	@$(MAKE) -C $(LIB_DIR)/libft full > /dev/null 2>&1
	@cp $(LIB_DIR)/libft/lib/$(LIB) $(LIB_DIR) > /dev/null 2>&1
	@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Static library '$(YELLOW)$(LIB)$(WHITE)' compiled."

$(OBJ_DIR):
	@$(MD) $(OBJ_DIR)
	@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Directory '$(YELLOW)$(OBJ_DIR)$(WHITE)' created."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -g3 -c $< -o $@
	@$(PRINT) "$(WHITE)[$(BLUE)✦$(WHITE)] File $(CYAN)'$<'$(WHITE) compiled."

$(NAME): $(OBJ_MAN) $(LIB_DIR)/$(LIB)
	@$(CC) $(FLAGS) $(OBJ_MAN) -L$(LIB_DIR) -lft -o $(NAME)
	@$(PRINT) "$(WHITE)[$(BLUE)^$(WHITE)] $(YELLOW)Mandatory$(WHITE) functions compiled."

all: $(NAME)
	@$(PRINT) "$(WHITE)[$(GREEN)✔$(WHITE)] Binary '$(YELLOW)$(NAME)$(WHITE)' created."

clean:
	@$(RM) $(OBJ_MAN)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(BLD_DIR)
	@$(PRINT) "$(WHITE)[$(BLUE)!$(WHITE)] Object files deleted."

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIB_DIR)/libft fclean > /dev/null 2>&1
	@$(RM) $(LIB_DIR)/$(LIB)
	@$(PRINT) "$(WHITE)[$(RED)✘$(WHITE)] Static library '$(YELLOW)$(LIB_DIR)/$(LIB)$(WHITE)' deleted."
	@$(RM) $(NAME)
	@$(PRINT) "$(WHITE)[$(RED)✘$(WHITE)] Binary '$(YELLOW)$(NAME)$(WHITE)' deleted."

re: fclean all

# INSTRUCTIONS FOR TESTING CASES

test2: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test2 test3 test5 test100 test500
