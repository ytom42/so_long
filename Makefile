# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 13:28:41 by ytomiyos          #+#    #+#              #
#    Updated: 2021/12/24 16:56:58 by ytomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS	+=	-g3 fsanitaize=address fsanitaize=leak

NAME	=	so_long

LIBFT	=	./libft/libft.a

SRCS	=	main.c \
			error.c \
			read_map.c \
			get_next_line.c \
			tool1.c \

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) libmlx.dylib -framework OpenGL -framework AppKit -o $@ $^

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
