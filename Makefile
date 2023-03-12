# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 16:50:38 by ysakine           #+#    #+#              #
#    Updated: 2023/03/12 22:50:57 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MATH = math_go/tuples_arth_oper.c math_go/tuples_negating.c math_go/tuples_magnitude.c math_go/tuples_product_operation.c math_go/tuples_normalization.c math_go/tuples_initialzer.c math_go/tuples_scalar_operations.c math_go/colours_initializer.c math_go/colour.c

SRC = ${SRC_MATH} parsing/parsing.c parsing/utils.c parsing/utils2.c utils/ft_atof.c get_next_line/get_next_line.c parsing/parsing_shapes.c parsing/parsing_sphere.c parsing/parsing_plane.c parsing/parsing_plane_utils.c parsing/parsing_cy.c parsing/parsing_cy_utils.c
obj = $(addprefix obj/, $(SRC:.c=.o))
NAME = miniRT
CFLAGS =-Wall -Wextra -Werror
libft = libft.a

all: ${NAME}

${NAME}: test ${obj}
	cd libft && make
	cc ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${libft} ${obj} src/main.c -o ${NAME}

test:
	@echo $(obj)

obj/%.o : src/%.c
	cc ${CFLAGS} -c $< -o $@

clean:
	cd libft && make clean
	rm -f ${obj}

fclean : clean
	cd libft && make fclean
	rm -f ${NAME}

re : fclean ${NAME}