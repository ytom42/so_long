# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 13:28:41 by ytomiyos          #+#    #+#              #
#    Updated: 2022/01/07 23:45:32 by ytomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS	+=	-g3 -fsanitize=address -fsanitize=leak

NAME	=	so_long

LIBFT	=	./libft/libft.a

SRCS	=	main.c \
			error.c \
			map_load.c \
			map_create.c \
			map_check.c \
			get_next_line.c \
			push_key.c \
			move.c \
			window_init.c \
			texture_load.c \
			create_img.c \
			ft.c \
			tool1.c \

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) libmlx.dylib -o $@ $^
# $(CC) $(CFLAGS) libmlx.dylib -framework OpenGL -framework AppKit -o $@ $^

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

test:
	$(CC) $(CFLAGS) -g libmlx.dylib $(LIBFT) -o $(NAME) $(SRCS)