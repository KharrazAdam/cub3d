# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 01:22:54 by akharraz          #+#    #+#              #
#    Updated: 2023/03/01 16:35:34 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RayTracer.out

SRC_TUPLES = src/tuples_arth_oper.c src/tuples_negating.c src/tuples_magnitude.c src/tuples_product_operation.c src/tuples_normalization.c src/tuples_initialzer.c src/tuples_scalar_operations.c

SRC_COLOUR = src/colours_initializer.c src/colours_operations.c

SRC_CANVAS = src/canvas.c

SRC_MATRICE = src/matrice_gen.c src/matrice_operationc.c src/matrice_inverting.c src/matrice_transformation.c src/clock.c

SRC_RAY = src/ray_init.c src/ray_position.c src/ray_intersection.c

SRC = src/utils.c src/main.c src/tick.c ${SRC_TUPLES} ${SRC_COLOUR} ${SRC_CANVAS} ${SRC_MATRICE} ${SRC_RAY}

INCLUDES = include/canvas.h include/matrice.h  include/ray.h  include/transformation.h  include/tuple.h include/types.h include/utils.h

OBJ = ${SRC:%.c=%.o}

CFLAGS = -g -O2 -lm -ldl -Wall -Wpointer-arith -finline-functions -ffast-math -funroll-all-loops -lmlx -lXext -lX11 -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ} ${INCLUDES}
	cc -fsanitize=address $(OBJ) $(CFLAGS) -o $(NAME)

# %.o : %.c
# 	cc -fsanitize=address -Imlx -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
