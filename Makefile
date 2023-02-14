# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 01:22:54 by akharraz          #+#    #+#              #
#    Updated: 2023/02/14 15:44:20 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RayTracer.out

SRC = src/main.c src/arth_oper.c src/negating.c src/magnitude.c src/product_operation.c\
		 src/normalization.c src/tick.c src/initialzer.c src/rbg.c
INCLUDES = include/ray.h include/tuple.h include/types.h
OBJ = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJ} ${INCLUDES}
	cc -Wall -Wextra -Werror $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	cc -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all