# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/09 15:06:36 by jwalle            #+#    #+#              #
#    Updated: 2015/09/25 12:21:13 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Wall -Werror -Wextra -g
CC = clang
SRCDIR = ./srcs/
ODIR = ./objs/
INC = -I./inc -I./libft -I./ft_printf/includes/
LINK = -L./libft -lft -L./ft_printf -lftprintf
BLU = tput setaf 4
GRN = tput setaf 2
WHT = tput setaf 7
RESET = tput sgr 0

SRC = main.c \
	stock.c \
	file_handling.c \
	options.c \
	misc.c \
	destroy.c \
	get_len.c \
	print_l.c \
	print_simple.c \
	sort.c \
	sort_st.c \
	print_dev.c \
	print_file.c \
	print_recursive.c \


OBJ		=	$(SRC:.c=.o)
OBJS	= 	$(addprefix $(ODIR), $(OBJ))

all :	$(LIB) $(NAME)

$(NAME) : $(OBJS)
	@$(BLU)
	mkdir -p $(ODIR)
	make -C libft
	make -C ft_printf
	@echo "Making $(NAME)..."
	@$(CC)  -o $(NAME) $^ $(LINK)
	@$(GRN)
	@echo "Done !"
	@$(RESET)

$(ODIR)%.o : $(SRCDIR)%.c
	@$(BLU)
	@echo "making objects..."
	mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $^ $(INC) -o $@
	@$(GRN)
	@echo "Done !"
	@$(RESET)


$(LIB):
	@$(BLU)
	@echo "Compiling libft..."
	@make -C libft
	@$(GRN)
	@echo "Done !"
	@$(BLU)
	@echo "Compiling printf..."
	make -C ft_printf
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


