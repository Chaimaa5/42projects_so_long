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
SRCS = so_long.c map.c inc/gnl/get_next_line.c inc/gnl/get_next_line_utils.c 
LIB = libft.a

OBJS = $(SRCS:.c=.o)

%.o : %.c
	   $(CC) $(CFLAGS) $< -c
$(NAME) : $(SRCS) $(LIB)
		$(CC) $(CFLAGS) $(SRCS) -o ${NAME} $(LIB)
$(LIB):
	make -C inc/libft
	cp inc/libft/libft.a ./




all : $(NAME) 

clean :
	rm -f ${OBJS}
	rm -f /inc/libft/*.o
fclean : clean
	rm -f so_long
	rm -f libft.a
	rm -f inc/libft/libft.a 

re : fclean all
