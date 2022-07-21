# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikang <sikang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:27:02 by sikang            #+#    #+#              #
#    Updated: 2022/07/21 19:08:17 by sikang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= so_long.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  map.c \
			  key.c \
			  image.c \

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make -C ./mlx
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		make clean -C ./mlx

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)
		make clean -C ./mlx

re			:	fclean all

.PHONY		:	all clean fclean re bonus
