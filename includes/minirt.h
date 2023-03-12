/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:40:39 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/10 23:17:44 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "get_next_line.h"
# include "ray.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_ambient
{
	int		is_init;
	int		ratio;
	t_colour	col;
}t_ambient;

typedef struct s_camera
{
	int is_init;
	t_point     position;
	t_vector direction;
	int h_fov;
}   t_camera;

typedef struct s_light
{
	int is_init;
	t_point position;
	float   brightness;
	t_colour    col;
}t_light;

typedef struct s_sphere
{
	t_point 	position;
	float   	diameter;
	t_colour	col;
}   t_sphere;

typedef struct s_cylinder
{
	t_point position;
	t_vector direction;
	float   diameter;
	float   height;
	t_colour    col;
}   t_cylinder;

typedef struct s_plane
{
   t_point  position;
   t_vector direction;
   t_colour col;
}   t_plane;

// utils
int		is_shape(char *shape);
int		check_float(const char *num);
float	ft_atof(const char *str);
int check_rgb(char **rgb);
// parsing
bool	check_and_fill_shapes(t_list **rt_file, t_list **sps, t_list **cls, t_list **pls);
// parsing --sphere--
bool	cf_sphere(char **par, t_list **sps);
// parsing --plane--
bool	cf_plane(char **par, t_list **pls);
bool	fill_plane_position(char *param, t_plane *pln);
bool	fill_plane_direction(char *param, t_plane *pln);
bool	fill_plane_direction(char *param, t_plane *pln);
bool	fill_plane_colour(char *param, t_plane *pln);

// parsing --cylindre--
bool	cf_cy(char **par, t_list **cls);
bool	fill_cy_position(char *param, t_cylinder *cy);
bool	fill_cy_direction(char *param, t_cylinder *cy);
void    clear_shapes(t_list **sps, t_list **cls, t_list **pls);

int		check_and_fill_light(char *attributes, t_light *light);
int		check_and_fill_lights(t_ambient *ambient_light, t_camera *camera, t_light *light, t_list **rt_file);
size_t	count_att(char  **att);
t_list	**read_file(int fd);
void	lst_pop_node(t_list **lst, t_list *node);

#endif