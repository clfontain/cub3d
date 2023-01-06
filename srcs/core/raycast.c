/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:29:19 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/05 11:44:16 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../minilibx-linux/mlx.h"
#include "../../includes/raycast.h"
#include "../../libft/libft.h"

void	raycast_convert_pos(t_cub3d *cub)
{
	cub->char_pos.x = cub->p_pos.y + 0.5;
	cub->char_pos.y = cub->p_pos.x + 0.5;
	cub->direct.x = 0;
	cub->direct.y = 0;
	if (cub->p_pos.dir == 'E')
		cub->direct.y = 1;
	else if (cub->p_pos.dir == 'W')
		cub->direct.y = -1;
	else if (cub->p_pos.dir == 'N')
		cub->direct.x = -1;
	else
		cub->direct.x = 1;
	cub->map[cub->p_pos.y][cub->p_pos.x] = '0';
}

void	raycast_init(t_cub3d *cub)
{
	double	dist;
	t_point	wall;
	double	angle;
	t_point	ray;
	int		line;

	angle = -PI / 6.1;
	line = 0;
	while (line <= cub->width)
	{
		ray = calcray(cub->direct, angle);
		wall = findptwall(cub->char_pos, ray, cub);
		dist = calculdistpercu(cub->char_pos, wall, angle);
		dist = calculheight(dist);
		rewriteline(cub, 640 - line, dist, wall);
		angle += (PI / 3) / 640.0;
		line++;
	}
}

t_point	calcray(t_point direct, double angle)
{
	t_point	ray;
	double	cosangle;
	double	sinangle;

	cosangle = cos(angle);
	sinangle = sin(angle);
	ray.x = direct.x * cosangle - direct.y * sinangle;
	ray.y = direct.x * sinangle + direct.y * cosangle;
	return (ray);
}

void	rewriteline(t_cub3d *cub, int line, double dist, t_point wall)
{
	int		y;
	char	*pixel;
	int		test;

	test = dist;
	y = 0;
	while (test > 320)
	{
		create_tex_coord(cub, wall, 64.0 / (dist * 2.0));
		test -= 64.0 / (dist * 2);
	}
	while (y < cub->height)
	{
		pixel = cub->img.addr + y * cub->img.size + line * cub->img.bpp / 8;
		if (y > cub->height / 2.0 + dist)
			*(int *) pixel = cub->c.color;
		else if (y < cub->height / 2.0 - dist)
			*(int *) pixel = cub->f.color;
		else
		{
			*(int *) pixel = select_color(cub, wall, 64.0 / (dist * 2));
		}
		y++;
	}
	create_tex_coord(0, wall, 0);
}

double	calculheight(double dist)
{
	double	hp;

	hp = 320 / dist ;
	return (hp);
}
