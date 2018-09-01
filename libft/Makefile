# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 12:19:38 by pavaudon          #+#    #+#              #
#    Updated: 2018/03/09 16:43:57 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SRC_DIR =	./src/
SRC = 		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_lstadd.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_strndup.c \
			ft_nb_len.c \
			ft_itoa_base.c \
			ft_ischar.c \
			ft_lltoa_base.c \
			ft_ulltoa_base.c \
			ft_ull_base_len.c \
			ft_strfjoin.c \
			ft_strfnjoin.c \
			ft_ull_base_len.c \
			ft_ll_base_len.c \
			ft_lltodst_base.c \
			ft_itodst_base.c \
			ft_ftoa.c \
			ft_flen.c \
			ft_ftodst.c \
			ft_get_min_max.c \
			ft_tabcpy.c \
			ft_tabffjoin.c \
			ft_tabfsjoin.c \
			ft_tabndup.c \
			ft_tabdup.c \
			ft_tabsub.c \
			get_next_line.c \
			ft_puttab.c \
			ft_is_sort.c \
			ft_strfjoinset.c \
			ft_strnjoinc.c \
			ft_incharset.c \
			ft_simple_printf.c

SRCS =		$(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR =	./obj/
OBJ = 		$(SRC:.c=.o)
OBJS =		$(addprefix $(OBJ_DIR),$(OBJ))

INC_DIR =	./includes/
INC =		libft.h
INCS =		$(addprefix $(INC_DIR),$(INC))

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m

all : 			$(NAME)

$(NAME) :		$(OBJ_DIR) $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "\n${_CYAN}	 	  \\              "
		@echo "		  _\\\,,          "
		@echo "	 	 \"-=\~           "
		@echo " 		    \\\\\~___^~   "
		@echo "		   _|/---\\\\\    "
		@echo "		   \        \     "
		@echo "		${_IPURPLE}${_WHITE}*${_GREEN}M${_YELLOW}A${_BLUE}G${_GREY}I${_CYAN}C ${_YELLOW}M${_WHITE}A${_BLUE}N${_GREEN}A${_YELLOW}G${_BLUE}E${_GREY}D${_GREEN}*${_IPURPLE}${_IGREY}\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS)
		@$(CC) $(CFLAGS) -c $< -o $@
#		@echo "*MAGIC IN PROCESS*"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean :
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean : 		clean
		@rm -f $(NAME)

re :			 fclean all
