# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 14:25:18 by pavaudon          #+#    #+#              #
#    Updated: 2018/08/17 15:26:15 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re norme

NAME		=	fdf

SRC_DIR	=	./src/
SRCS		=	$(addprefix $(SRC_DIR),$(SRC))
SRC			= 	main.c

OBJ_DIR	=	./obj/
OBJS		=	$(addprefix $(OBJ_DIR),$(OBJ))
OBJ			=	$(SRC:.c=.o)

INC			=	./includes/
INCLIB		=	./libft/includes/
INCS		=	$(INC) $(INCLIB)

CC			=	gcc -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address

CFLAGS		=	-Wextra -Wall -I$(INC) -I$(INCLIB) -I /usr/local/include

all:			$(NAME)


$(NAME):		$(OBJ_DIR) $(OBJS)
				@make -C libft/
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./libft -lft
				@echo "fdf is made"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS)
				@$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)


clean:
				@rm -rf $(OBJS)
				@rm -rf $(OBJ_DIR)
				@make clean -C libft


fclean:			clean
				@rm -rf libft/libft.a
				@rm -rf $(NAME)

re:			fclean all
