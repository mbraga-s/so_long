# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 15:27:59 by mbraga-s          #+#    #+#              #
#    Updated: 2023/08/29 15:38:56 by mbraga-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = map checker so_long path moves place_tiles frees\
	 ./getnextline/get_next_line ./getnextline/get_next_line_utils \

LIB = $(NAME).a

LIBFT_LIB = ./libft/libft.a
LIBFT_PATH = ./libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MILIB = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx -framework OpenGL -framework AppKit

MLX_LIB_DIR = minilibx-linux/
MLX_INCLUDE = -I minilibx-linux/

INC = -Iincludes -I/usr/include -Imlx_linux

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -fr

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(LIB)
		make -s -C minilibx-linux/
		$(CC) $(CFLAGS) $(LIB) $(LIBFT_LIB) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

$(LIB): $(SRCS:=.o)
		ar rc $(LIB) $(SRCS:=.o)

$(LIBFT_LIB):  $(shell make -C $(LIBFT_PATH) -q)
	make -C$(LIBFT_PATH)

clean: libftclean
	$(RM)	$(SRCS:=.o)

libftclean: $(shell make -C $(LIBFT_PATH) -q)
	make -C$(LIBFT_PATH) clean

libftfclean: $(shell make -C $(LIBFT_PATH) -q)
	make -C$(LIBFT_PATH) fclean

fclean: clean libftfclean
		$(RM)	$(NAME) $(NAME).a

re:	fclean	$(NAME)

.PHONY: clean fclean re