/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:21:19 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/21 11:57:22 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

# include "libft.h"
# include "parsing.h"


# define W_WIDTH 1080
# define W_HEIGHT 1080
# define MOVESPEED 5.0
# define PI 3.14159265

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	ang;
}	t_coordinates;

typedef struct s_map
{
	int				checker;
	char			*n_textures;
	char			*s_textures;
	char			*e_textures;
	char			*w_textures;
	int				f_col;
	int				c_col;
	char			**map;
	int				map_h;
	int				map_w;
	t_coordinates	p_pos;
	t_vars			mlx;
} t_map;

double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
void	move_player_forward(t_coordinates *p_pos);
void	move_player_backward(t_coordinates *p_pos);
void	rotate_player_left(t_coordinates *p_pos);
void	rotate_player_right(t_coordinates *p_pos);
void	start(t_map *map);


/**
 * II- parsing localisation and colours
*/
char	*get_key(char *str);
bool	is_number(char *num);
bool	generate_rgb(int *f_col, char **spl);
bool	get_rgb(char *str, int *f_col);
void	clear_attr(t_map *map);
bool	fill_text(char *key, char *str, t_map *map);
bool	ft_fill(char *str, t_map *map);
bool	fill_colour(char *key, char *str, t_map *map);
bool	check_elements(t_map *map, int fd);
bool	get_rgb(char *str, int *f_col);
size_t	count_commas(char *tmp);
void	clear_attr(t_map *map);

/**
 * III- parsing mini map
 *  1- check map
 *   a- fill it in alinked list
 *   b- fill it in an array (as yasser requested)
 *	2-parsing utils
*/
int		parsing(t_map *map, char *av);
bool	check_map(t_map *map, int fd);
bool	fill_map_list(t_list **list, int fd, int *map_w);
bool	fill_map_list(t_list **list, int fd, int *map_w);
bool	map_valid(t_map *map);

bool	sur_check(int i, int j, char **map);

bool	is_player(char c);
bool	is_valid(char c);
bool	is_number(char *num);
size_t	count_att(char **attr);
#endif