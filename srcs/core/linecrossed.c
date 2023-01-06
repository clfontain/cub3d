/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linecrossed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:38:49 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/05 10:08:31 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../minilibx-linux/mlx.h"
#include "../../includes/raycast.h"
#include "../../libft/libft.h"
#include <time.h>

t_point	bothlinecross(t_point start, t_point try, t_cub3d *cub, t_point direct)
{
	t_point	choix;
	double	coef;
	double	b;

	coef = (try.y - start.y) / (try.x - start.x);
	b = -(coef * try.x) + try.y;
	if (direct.x < 0)
	{
		choix.x = (int)try.x + 1 -0.000000000001;
		cub->wallhit = SOUTH;
	}
	else
	{
		choix.x = (int)try.x ;
		cub->wallhit = NORTH;
	}
	choix.y = coef * choix.x + b;
	if ((int)choix.y == (int)start.y)
		return (choix);
	choix = bothlinecross2(start, try, cub, direct);
	return (choix);
}

t_point	bothlinecross2(t_point start, t_point try, t_cub3d *cub, t_point direct)
{
	t_point	choix;
	double	coef;
	double	b;

	coef = (try.x - start.x) / (try.y - start.y);
	b = -(coef * try.y) + try.x;
	if (direct.y < 0)
	{
		choix.y = (int)try.y + 1 - 0.0000000000001;
		cub->wallhit = WEST;
	}
	else
	{
		choix.y = (int)try.y;
		cub->wallhit = EAST;
	}
	choix.x = coef * choix.y + b;
	if ((int)choix.x == (int)start.x)
		return (choix);
	choix.x = (int)try.x;
	return (choix);
}

t_point	singlelinecross(t_point start, t_point try, int cases)
{
	double	coef;
	double	b;

	if (cases == 1 || cases == 3)
	{
		coef = (try.y - start.y) / (try.x - start.x);
		b = -(coef * try.x) + try.y;
		try.x = (int)try.x;
		if (cases == 3)
			try.x += 1;
		try.y = coef * try.x + b;
	}
	else if (cases == 2 || cases == 4)
	{
		coef = (try.x - start.x) / (try.y - start.y);
		b = -(coef * try.y) + try.x;
		try.y = (int)try.y;
		if (cases == 4)
			try.y += 1;
		try.x = coef * try.y + b;
	}
	return (try);
}

double	calculdistpercu(t_point a, t_point b, double angle)
{
	double	res;

	res = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return (res * cos(angle));
}

t_point	findptwall(t_point start, t_point vdirection, t_cub3d *cub)
{
	t_point	try;

	try.x = start.x + (vdirection.x);
	try.y = start.y + (vdirection.y);
	if (!((int)try.x - (int)start.x) && !((int)try.y - (int)start.y))
		return (findptwall(try, vdirection, cub));
	else if (((int)try.x - (int)start.x) && ((int)try.y - (int)start.y))
	{
		try = bothlinecross(start, try, cub, vdirection);
		if (cub->map[(int)try.x][(int)try.y] == '1')
			return (try);
	}
	else if ((int)try.x - (int)start.x > 0
		&& cub->map[(int)try.x][(int)try.y] == '1')
		return (cub->wallhit = NORTH, singlelinecross(start, try, 1));
	else if ((int)try.y - (int)start.y > 0
		&& cub->map[(int)try.x][(int)try.y] == '1')
		return (cub->wallhit = EAST, singlelinecross(start, try, 2));
	else if ((int)try.x - (int)start.x < 0
		&& cub->map[(int)try.x][(int)try.y] == '1')
		return (cub->wallhit = SOUTH, singlelinecross(start, try, 3));
	else if ((int)try.y - (int)start.y < 0
		&& cub->map[(int)try.x][(int)try.y] == '1')
		return (cub->wallhit = WEST, singlelinecross(start, try, 4));
	return (findptwall(try, vdirection, cub));
}
