# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 13:40:07 by cel-mhan          #+#    #+#              #
#    Updated: 2022/03/03 13:40:09 by cel-mhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c map.c inc/gnl/get_next_line.c inc/gnl/get_next_line_utils.c moves.c draw.c utils.c
INC = -lmlx -framework OpenGL -framework AppKit

LIBFT_A = libft.a
LIBF_DIR = inc/libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC)  $(CFLAGS)  -Imlx -c $< -o $@
$(NAME): $(OBJ)
	make -C $(LIBF_DIR)
	cp inc/libft/libft.a .
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)

all : $(NAME) 

clean :
	rm -f ${OBJ}
	rm -f inc/libft/*.o
fclean : clean
	rm -f so_long
	rm -f $(LIBFT_A)
	rm -f inc/libft/libft.a 
re : fclean all
