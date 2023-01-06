/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:33:27 by cfontain          #+#    #+#             */
/*   Updated: 2023/01/04 15:51:52 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/raycast.h"

bool	start_cub3d(t_cub3d *data)
{
	data->width = 640;
	data->height = 640;
	data->win = mlx_new_window(data->ptr, data->width,
			data->height, data->map_name);
	if (data->win == NULL)
		return (ft_printf_error("Error\nWindow error\n"), false);
	if (createbaseimg(data))
		return (ft_printf_error("Error\nImage error\n"), false);
	raycast_convert_img(data);
	raycast_convert_pos(data);
	raycast_init(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img.img, 0, 0);
	mlx_hook(data->win, 02, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, destroy_data, data);
	mlx_loop (data->ptr);
	return (true);
}

int	createbaseimg(t_cub3d *data)
{
	int		y;
	int		x;
	char	*pixel;

	data->img.img = mlx_new_image(data->ptr, data->width, data->height);
	if (data->img.img == NULL)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.size, &data->img.endian);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			pixel = data->img.addr + y * data->img.size + x * data->img.bpp / 8;
			*(int *) pixel = data->f.color;
			if (y > (data->height / 2))
				*(int *) pixel = data->c.color;
			x++;
		}
		y++;
	}
	return (0);
}

void	raycast_convert_img(t_cub3d *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i].img = data->ptr_img[i];
		data->texture[i].addr = mlx_get_data_addr(data->texture[i].img,
				&data->texture[i].bpp,
				&data->texture[i].size, &data->texture[i].endian);
		i++;
	}
}
