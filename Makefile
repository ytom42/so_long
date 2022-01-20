# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 13:28:41 by ytomiyos          #+#    #+#              #
#    Updated: 2022/01/20 12:07:56 by ytomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	so_long

LIBFT	=	./libft/libft.a

MLXDIR	=	./minilibx_mms_20200219

LIBMLX	=	$(MLXDIR)/libmlx.dylib

SRCS	=	main.c \
			end.c \
			map_load.c \
			map_create.c \
			map_check.c \
			get_next_line.c \
			push_key.c \
			move.c \
			create_window.c \
			texture_load.c \
			create_img.c \
			ft.c \
			tool.c \

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(LIBMLX) $^ -o $@

$(LIBFT):
			make -C ./libft

clean:
		make clean -C ./libft
		rm -f $(OBJS)

fclean:	clean
		rm -f $(LIBFT)
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
