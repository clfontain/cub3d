/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:11:32 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/04 13:25:35 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point	create_tex_coord(t_cub3d *data, t_point wall, double step)
{
	t_point			texture_coordinate;
	static double	y;

	if (!data)
	{
		y = step;
		return (wall);
	}
	if (data->wallhit == NORTH || data->wallhit == SOUTH)
	{
		texture_coordinate.y = (wall.y - (int)wall.y) * 64;
	}
	else
	{
		texture_coordinate.y = (wall.x - (int)wall.x) * 64;
	}
	texture_coordinate.x = floor(y);
	y += step;
	return (texture_coordinate);
}

int	select_color(t_cub3d *data, t_point wall, double step)
{
	int		color;
	char	*pixel;
	t_point	texture_coordinate;

	texture_coordinate = create_tex_coord(data, wall, step);
	pixel = data->texture[data->wallhit -1].addr
		+ (int)texture_coordinate.x * data->texture[data->wallhit -1].size
		+ (int)texture_coordinate.y * data->texture[data->wallhit -1].bpp / 8;
	color = *(int *) pixel;
	return (color);
}
