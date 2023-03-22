/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:45:01 by ysakine           #+#    #+#             */
/*   Updated: 2023/03/19 21:18:41 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_player_forward(t_coordinates *p_pos)
{
	p_pos->x += cos(deg_to_rad(p_pos->ang));
	p_pos->y += sin(deg_to_rad(p_pos->ang));
}

void	move_player_backward(t_coordinates *p_pos)
{
	p_pos->x -= cos(deg_to_rad(p_pos->ang));
	p_pos->y -= sin(deg_to_rad(p_pos->ang));
}

void	rotate_player_left(t_coordinates *p_pos)
{
	if (p_pos->ang <= 359 && p_pos->ang >= 359 - MOVESPEED)
		p_pos->ang = 0;
	else
		p_pos->ang++;
}

void	rotate_player_right(t_coordinates *p_pos)
{
	if (p_pos->ang >= 0 && p_pos->ang <= MOVESPEED)
		p_pos->ang = 359;
	else
		p_pos->ang -= MOVESPEED;
}