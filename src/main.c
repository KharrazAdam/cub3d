/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:02:15 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/11 02:03:34 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minirt.h"

uint32_t	ray_colour()
{
	return (0x00FFFF);
}

int main(int ac, char **av)
{
	t_list		**rt_file;
	t_ambient	ambient;
	t_camera	 cam;
	t_light		light;
	t_list		**sps = ft_calloc(sizeof(t_list *), 1);
	t_list		**pls = ft_calloc(sizeof(t_list *), 1);
	t_list		**cls = ft_calloc(sizeof(t_list *), 1);
	int			fd;

	if (ac != 2 || ft_strncmp(&av[1][ft_strlen(av[1]) - 3],".rt", 4))
	{
		ft_putstr_fd("Error\nplease provide a valid rt file lah ij3al rebbi y7enn 3lik\n", 2);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	rt_file = read_file(fd);
	if (check_and_fill_lights(&ambient, &cam, &light, rt_file) != 3)
	{
		ft_putstr_fd("Error\nsomething went wrong\n", 2);
		ft_lstclear(rt_file,free);
		return (1);
	}
	if (check_and_fill_shapes(rt_file, sps, pls, cls) == false)
		return ft_lstclear(rt_file, free), -1;

	//-------------start the rendring--------------//

	t_vars		mlx;
	t_colour	col;
	int x, y = 0;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "fayrouz");
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, ray_colour());
			x++;
		}
		y++;
	}
	mlx_loop(mlx.mlx);
	close(fd);
	clear_shapes(sps, pls, cls);
	ft_lstclear(rt_file, free);
	return (0);
}
