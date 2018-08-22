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

NAME_1		=	fdf

SRC_DIR_1	=	./src/
SRCS_1		=	$(addprefix $(SRC_DIR_1),$(SRC_1))
SRC_1		=	main.c\
				parser.c\
				ft_point.c\
#				ft_tracer.c

OBJ_DIR_1	=	./obj/
OBJS_1		=	$(addprefix $(OBJ_DIR_1),$(OBJ_1))
OBJ_1		=	$(SRC_1:.c=.o)

INC			=	./includes/
INCLIB		=	./libft/includes/
INCS		=	$(INC) $(INCLIB)

CC			=	gcc -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address

CFLAGS		=	-Wextra -Wall -I$(INC) -I$(INCLIB) -I /usr/local/include

all:			$(NAME_1)


$(NAME_1):		$(OBJ_DIR_1) $(OBJS_1)
				@make -C libft/
				@$(CC) $(CFLAGS) $(OBJS_1) -o $(NAME_1) -L./libft -lft
				@echo "fdf is made"

$(OBJ_DIR_1)%.o:	$(SRC_DIR_1)%.c $(INCS)
				@$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR_1):
				@mkdir -p $(OBJ_DIR_1)


clean:
				@rm -rf $(OBJS_1)
				@rm -rf $(OBJ_DIR_1)
				@make clean -C libft


fclean:			clean
				@rm -rf libft/libft.a
				@rm -rf $(NAME_1)

re:			fclean all
