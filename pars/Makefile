# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 13:36:06 by akharraz          #+#    #+#              #
#    Updated: 2023/03/21 06:17:58 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PARSING = $(addprefix parsing/, parsing.c parsing_file.c parsing_elements.c parsing_sur.c parsing_map.c parsing_utils.c parsing_col.c)
SRC = ${SRC_PARSING} main.c get_next_line/get_next_line.c movement/player_movement.c utils/utils.c rendering/hooks.c
obj = $(addprefix obj/, $(SRC:.c=.o))
INCLUDES = $(addprefix inc/, libft.h cub3d.h parsing.h get_next_line.h)


NAME = Cub3d
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
libft = libft.a

all: ${NAME}

${NAME}: ${obj} ${INCLUDES}
	cd libft && make
	cc ${CFLAGS} ${MLXFLAGS} ${libft} ${obj} -o ${NAME}

obj/%.o : src/%.c
	@mkdir -p $(dir $@)
	cc ${CFLAGS} -Imlx -c $< -o $@

clean:
	cd libft && make clean
	rm -f ${obj}

fclean : clean
	cd libft && make fclean
	rm -f ${NAME}

re : fclean ${NAME}