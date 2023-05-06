/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:21:19 by ysakine           #+#    #+#             */
/*   Updated: 2023/05/06 18:19:11 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

# include "libft.h"
# include "parsing.h"

#define FS 30

#define W 119
#define S 115
#define A 97
#define D 100
#define ESC 65307
#define LEFT 65361
#define RIGHT 65363
#define SPEED 0.05

#define ARR_R 1
#define ARR_L 2
#define UP 4
#define DOWN 8
#define LF 16
#define RH 32

#define HIGHT 960
#define WIDTH 1280
#define FOV M_PI / 3
#define HORIZONTAL_INTER 1
#define VERTICAL_INTER 0

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_ray {
	double	x;
	double	y;
	double	diatance;
	bool	inter;
}				t_ray;

typedef struct s_coordinates
{
	double		x;
	double		y;
	double		ang;
}	t_coordinates;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_data;
typedef struct s_map
{
	char			hook_is;
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
	t_ray			ray;
	t_data			no;
	t_data			so;
	t_data			ea;
	t_data			we;
} t_map;


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

// utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//keys
int red_cross(void *map);
int key_but(int key, t_map *map);
int	key_rel(int	key, t_map *map);

// pgritd
int		draw_map(t_map *map);
void	draw_grid(t_data *img, int i, int j, t_map *map);

// movement
void	move(t_map *map);
// casting
void	cast(t_map *map, t_data *data);
t_ray	vertical_intersection(t_map *map, double angle);
t_ray	hor_intersection(t_map *map, double angle);

// casting utils
double	pyth(double x, double y, double x1, double y1);
double	fix_ang(double angle);

// projection
void	project(t_ray ray, int wid_i, t_data *img, t_map *map, double anglr);
#endif