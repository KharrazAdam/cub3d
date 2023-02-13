# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 01:22:54 by akharraz          #+#    #+#              #
#    Updated: 2023/02/13 03:45:18 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RayTracer.out

SRC = src/main.c src/arth_oper.c src/negating.c src/magnitude.c
INCLUDES = include/ray.h include/tuple.h
OBJ = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJ} ${INCLUDES}
	cc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

%.o : %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all