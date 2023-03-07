/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:39:48 by akharraz          #+#    #+#             */
/*   Updated: 2023/03/08 00:39:11 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

typedef struct s_sphere
{
	t_point position;
	float   radius;
	float   hit;
}t_sphere;

typedef struct s_camera
{
	t_point position;
	t_vector vector;
	float  zoom;
}t_camera;

void    setupScene(t_camera *cam, t_sphere *sph)
{
	cam->position = point_initializer(0, 0, 3.5);
	cam->vector = vetor_initializer(0, 0, -1);
	cam->zoom = 0.1;

	sph->position = point_initializer(0, 0, -3.4);
	sph->radius = 0.2;
}

bool	SolveQuadratic(float a, float b, float c, float *t0, float *t1)
{
	float	disc;

	disc = (b * b) - (4 * a * c);
	if (disc < 0)
		return false;
	if (disc == 0)
	{
		*t0 = -b / (2 * a);
		*t1 = -b / (2 * a);
		return true;
	}
	*t0 = (-b + sqrt(disc)) / (2 * a);
	*t0 = (-b - sqrt(disc)) / (2 * a);
	return true;	
}

bool	intersect(t_vector direction, t_camera cam, t_sphere sph)
{
	t_vector L;

	L.tuple = tuples_Subtracting(cam.position.tuple, sph.position.tuple);
	float	a = tuple_dot_product(direction.tuple, direction.tuple);
	float	b = 2 * tuple_dot_product(direction.tuple, L.tuple);
	float	c = tuple_dot_product(L.tuple, L.tuple) - pow(sph.radius, 2);

	float	t0;
	float	t1;

	if (SolveQuadratic(a, b, c, &t0, &t1) == true)
		return true;
	return false;
}

uint32_t ray_tracer(t_vector direction, t_camera cam, t_sphere sph, int x, int y)
{
	if (intersect(direction, cam, sph))
	{
		printf("%d----------%d\n", x, y);
		return 0xf0ff00 ;
	}
	return 0x00c3f0;
}

int main(void)
{
	t_vars      mlx;
	t_camera    cam;
	t_sphere    sph;
	t_vector	direction;

	int x = 0;
	int y = 0;

	setupScene(&cam, &sph);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "fayrouz");
	while (x < 500)
	{
		y = 0;
		while (y < 500)
		{
			direction.tuple = nrml(tuples_Subtracting(vetor_initializer(x, y, cam.zoom).tuple, cam.position.tuple));
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, ray_tracer(direction, cam, sph, x, y));
			y++;
		}
		x++;
	}
	mlx_loop(mlx.mlx);
	return 0;
}
