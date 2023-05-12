# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 13:36:06 by akharraz          #+#    #+#              #
#    Updated: 2023/05/12 17:59:31 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PARSING = $(addprefix parsing/, parsing.c parsing_file.c parsing_elements.c parsing_sur.c parsing_map.c parsing_utils.c parsing_col.c)
SRC_GNL = $(addprefix get_next_line/, get_next_line.c)
SRC_UTILS = $(addprefix utils/, utils.c)
SRC_PGRID = $(addprefix pgrid/, two_d.c movement.c cast.c cast_utils.c keys.c show_wall.c)
SRC = ${SRC_PARSING} $(SRC_GNL) ${SRC_UTILS} $(SRC_PGRID) main.c
LIBFT = ./libft/libft.a

NAME = Cub3D

MLX_DIR = mlx_linux
MLX = libmlx.a
CC = gcc

# diff entre .a et .dylib
# .a = lib static, les fonctions utilisees sont directement ecrite dans le binaire
# .dylib = lib dynamique, les fonctions doivent etre chargees au momnent ou on lance le binaire

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

OBJ_DIR = ./obj
SRC_DIR = ./src
INC_DIR = ./inc

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

# -C faire make comme si on etait dana le dossier
# -j multisreder / ameliore la vitesse de compliation
# Pas de regle opti car makefile mlx pas compatible
all:
	@$(MAKE) -j $(NAME)

# permet de pouvoir comparer la derniere modification de la dep par rapport a la regle
# -L donner le nom du dossier / -l donner le nom le la lib
# loader path = ecrit le chemin de la mlx dans le binaire pour pouvoir la retrouver au moment ou on lance le binaire
$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext $(LIBFT)
		@echo $(NAME) : Created !

# si le .c est plus recent que le .o on rentre dans la regle
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	@rm -rf $(OBJ)
	@echo "obj deleted"

fclean:	clean
	@rm -rf $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re

# Utilise les .d (et ignore s'ils n'existe pas)
-include $(DPD)