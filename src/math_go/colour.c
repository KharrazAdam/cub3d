// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   colour.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/12 22:51:07 by akharraz          #+#    #+#             */
// /*   Updated: 2023/03/12 22:51:19 by akharraz         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */


// #include "../../includes/minirt.h"

// uint32_t	generate_colour(int x, int y)
// {
// 	float	red = (float)x / 1000;
// 	float	green = (float)y / 1000;
// 	float	blue = 0.25;
// 	return colour_initializer(red * 255.999, green * 255.999, blue * 255.999).rgb;
// }

// bool	start(void)
// {
// 	t_vars	vars;
// 	int		height = 1000;
// 	int		width = 1000;

// 	vars.mlx = mlx_init();
// 	if (vars.mlx == NULL)
// 		return (false);
// 	vars.win = mlx_new_window(vars.mlx, width, height, "fayrouz");
// 	if (vars.win == NULL)
// 		return (false);
// 	while (height)
// 	{
// 		width = 1000;
// 		while (width)
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, width, 1000 - height, generate_colour(width, height));
// 			width--;
// 		}
// 		height--;
// 	}
// 	mlx_loop(vars.mlx);
// 	return (true);
// }

