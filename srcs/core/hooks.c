/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:04:07 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/05 10:41:35 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/raycast.h"

int	key_hook(int keycode, t_cub3d *data)
{
	if (keycode == 65307)
		destroy_data(data);
	if (ft_do_mov(data, keycode) || ft_do_lateral_mov(data, keycode)
		|| ft_do_rotate(data, keycode))
	{
		raycast_init(data);
		mlx_put_image_to_window(data->ptr, data->win, data->img.img, 0, 0);
	}
	return (0);
}

int	ft_do_lateral_mov(t_cub3d *data, int key)
{
	t_point	trigo;
	t_point	tmp;

	trigo = create_point(cos(PI / 2), sin(PI / 2));
	tmp = create_point(data->char_pos.x, data->char_pos.y);
	if (key == 'a')
		tmp = addpoint(tmp, data->direct.x / 5 * trigo.x - data->direct.y / 5
				* trigo.y, data->direct.x / 5 * trigo.y
				+ data->direct.y / 5 * trigo.x);
	else if (key == 'd')
		tmp = addpoint(tmp, -(data->direct.x / 5 * trigo.x
					- data->direct.y / 5 * trigo.y),
				-(data->direct.x / 5 * trigo.y + data->direct.y / 5 * trigo.x));
	else
		return (0);
	if (data->map[(int)tmp.x][(int)tmp.y] != '1' && (data->map[(int)tmp.x]
		[(int)data->char_pos.y] != '1' || data->map[(int)data->char_pos.x]
		[(int)tmp.y] != '1'))
			data->char_pos = create_point(tmp.x, tmp.y);
	else
		return (0);
	return (1);
}

int	ft_do_rotate(t_cub3d *data, int key)
{
	if (key == 65361)
	{
		data->direct.x = data->direct.x * cos(0.05)
			- data->direct.y * sin(0.05);
		data->direct.y = data->direct.x * sin(0.05)
			+ data->direct.y * cos(0.05);
		data->direct = ft_renorm(data->direct);
		return (1);
	}
	if (key == 65363)
	{
		data->direct.x = data->direct.x * cos(-0.05)
			- data->direct.y * sin(-0.05);
		data->direct.y = data->direct.x * sin(-0.05)
			+ data->direct.y * cos(-0.05);
		data->direct = ft_renorm(data->direct);
		return (1);
	}
	return (0);
}

int	ft_do_mov(t_cub3d *data, int key)
{
	t_point	tmp;

	tmp.x = data->char_pos.x;
	tmp.y = data->char_pos.y;
	if (key == 'w' || key == 65362)
	{
		tmp.x += data->direct.x / 5;
		tmp.y += data->direct.y / 5;
	}
	else if (key == 's' || key == 65364)
	{
		tmp.x -= data->direct.x / 5;
		tmp.y -= data->direct.y / 5;
	}
	else
		return (0);
	if (data->map[(int)tmp.x][(int)tmp.y] != '1' && (data->map[(int)tmp.x]
		[(int)data->char_pos.y] != '1' || data->map[(int)data->char_pos.x]
		[(int)tmp.y] != '1'))
		data->char_pos = create_point(tmp.x, tmp.y);
	else
		return (0);
	return (1);
}
