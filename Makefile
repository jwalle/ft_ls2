# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/09 15:06:36 by jwalle            #+#    #+#              #
#    Updated: 2015/07/12 13:36:15 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Wall -Werror -Wextra -g
CC = GCC
SRCDIR = .
ODIR = ./objs/
LIB = ./libft/libft.a
SRCO = $(SRC:.c=.o)
BLU = tput setaf 4
GRN = tput setaf 2
WHT = tput setaf 7
RESET = tput sgr 0

SRC = main.c \
	stock.c \
	file_handling.c \
	options.c \
	misc.c \

OBJ = $(SRC:.c=.o)

all : $(LIB) $(NAME)

$(NAME) : objects
	@$(BLU)
	@echo "Making $(NAME)..."
	@$(CC) $(addprefix $(ODIR), $(OBJ)) -o $(NAME) -L libft -lft
	@$(GRN)
	@echo "Done !"
	@$(RESET)

objects:
	@$(BLU)
	@echo "making objects..."
	@$(CC) $(CFLAGS) -c $(SRC) -I ./includes -I libft/includes
	@mkdir -p $(ODIR)
	@mv $(OBJ) $(ODIR)
	@$(GRN)
	@echo "Done !"
	@$(RESET)

$(LIB):
	@$(BLU)
	@echo "Compiling libft..."
	@make -C libft
	@$(GRN)
	@echo "Done !"
	@$(RESET)

clean:
	@make -C libft fclean
	@$(BLU)
	@echo "Cleaning objects..."
	@rm -rf $(ODIR)
	@$(GRN)
	@echo "Done !"
	@$(RESET)

fclean: clean
	@$(BLU)
	@echo "Deleting executable..."
	@rm -rf $(NAME)
	@$(GRN)
	@echo "Done !"
	@$(RESET)

re: fclean all
	@$(GRN)
	@echo "Project reset and Rebuild !"
	@$(RESET)


