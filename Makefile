# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:01:54 by pudry             #+#    #+#              #
#    Updated: 2024/09/11 11:27:10 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET = \\033[0m
BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0; 33m

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra
INCLUDES = includes/
LIBFT = libft/
LIBFT_FILE = libft/libft.a
LIBFT_INCLUDES = $(LIBFT)/includes


INPUT = 1658735832 -65227727 3

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=objet/%.o)


all: $(NAME) header
	@echo "${GREEN}push_swap compilation success"

$(NAME): $(SRC) $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(OBJ) $(FLAGS) $(LIBFT_FILE) -o $(NAME)

clean:
	@rm -rf objet/
	@make clean -C $(LIBFT)
	@echo "${GREEN}ft_printf clean${RESET}"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "${GREEN}ft_printf fclean${RESET}"

re: fclean all

objet/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES) -I $(LIBFT_INCLUDES)

check:
	./$(NAME) $(INPUT)

leak:
	leaks --atExit -- ./$(NAME) $(INPUT)

header :
	@echo "${GREEN}"
	@echo "		   __________"
	@echo "		 . ---------- ."
	@echo "		 | .--------. |"
	@echo "		 | | ${BLUE}COMPILE${GREEN}| |       __________       ___"
	@echo "		 | | ${BLUE}FILE${GREEN}   | |      /__________\\    {~${RED}.${GREEN}_${RED}.${GREEN}~}"  
	@echo "	.--------|  --------  |------|    --=-- |-----( Y )---."
	@echo "	|         ----,-.-----       |o ======  |    ()~*~()  | "
	@echo "	|       ______|_|_______     |__________|    (_)-(_)  | "
	@echo "	|      /  %%%%%%%%%%%%  \\                             | "
	@echo "	|     /  %%%%%%%%%%%%%%  \\                            | "
	@echo "	|     ^^^^^^^^^^^^^^^^^^^^                            | "
	@echo "	+-----------------------------------------------------+"
	@echo "	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ "
	@echo "${RESET}"



.PHONY : fclean re all header clean check leak