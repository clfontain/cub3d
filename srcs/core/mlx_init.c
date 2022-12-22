/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:33:27 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/21 15:17:14 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	start_cub3d(t_cub3d *data)
{
	int	width;
	int	height;

	width = 640;
	height = 640;
	data->win = mlx_new_window(data->ptr, width, height, data->map_name);
	if (data->win == NULL)
		return (ft_printf_error("Error\nWindow error\n"), false);
	mlx_pixel_put(data->ptr, data->win, 320, 320, data->f.color);
	mlx_pixel_put(data->ptr, data->win, 320, 321, data->f.color);
	mlx_pixel_put(data->ptr, data->win, 321, 320, data->f.color);
	mlx_pixel_put(data->ptr, data->win, 321, 321, data->f.color);
	mlx_hook(data->win, 17, 1L << 2, NULL, NULL);
	mlx_loop (data->ptr);
	return (true);
}
