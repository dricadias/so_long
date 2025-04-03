# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 14:03:16 by adias-do          #+#    #+#              #
#    Updated: 2025/04/03 18:57:48 by adias-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lm -lmlx -lXext -lX11

LIBFTDIR = libft
RM = rm -rf

SRCS = srcs/map.c \
	srcs/rendering.c \
	srcs/create_map.c \
	srcs/so_long.c \
	srcs/free.c \
	#srcs/testing_mlx.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -L ./libft -L mlx

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@make -s -C $(LIBFTDIR)
	make -C mlx
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME) -lft ${MLX_FLAGS}

#$(BONUS): ${OBJS} ${BONUS_OBJ}
#	@make -s -C $(LIBFTDIR)
#	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJS_2) -o $(BONUS) ${INCLUDE}

all: $(NAME) #$(BONUS)

#bonus: $(BONUS)

clean:
	$(RM) $(OBJS)
	@make -s -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -s -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
