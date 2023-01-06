/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:14:57 by cfontain          #+#    #+#             */
/*   Updated: 2023/01/04 14:50:00 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	destroy_data(t_cub3d *data)
{
	int	i;

	i = 0;
	destroy_data2(data);
	while (i < 4)
	{
		if (data->ptr_img[i])
			mlx_destroy_image(data->ptr, data->ptr_img[i]);
		i++;
	}
	if (data->win != NULL)
		mlx_destroy_window(data->ptr, data->win);
	if (data->ptr != NULL)
	{
		mlx_destroy_display(data->ptr);
		free(data->ptr);
	}
	exit (0);
	return (0);
}

void	destroy_data2(t_cub3d *data)
{
	if (data->map != NULL)
		destroy_str(data->map);
	if (data->little != NULL)
		destroy_str(data->little);
	if (data->path != NULL)
		destroy_tab_stack(data->path);
	if (data->t_path != NULL)
		destroy_tab_stack(data->t_path);
	if (data->img.img != NULL)
		mlx_destroy_image(data->ptr, data->img.img);
}

bool	init_little(t_cub3d *data)
{
	int	i;

	data->little = ft_calloc(sizeof(char *), 7);
	if (data->little == NULL)
		return (false);
	data->little[0] = ft_strdup("NO");
	data->little[1] = ft_strdup("SO");
	data->little[2] = ft_strdup("WE");
	data->little[3] = ft_strdup("EA");
	data->little[4] = ft_strdup("F");
	data->little[5] = ft_strdup("C");
	i = 0;
	while (i < 6)
	{
		if (data->little[i] == NULL)
			return (destroy_str(data->little), false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_cub3d	data;

	if (argc != 2)
		return (ft_printf_error("Error\nCub3d needs a path to a map\n"), 1);
	ft_memset(&data, 0, sizeof(data));
	data.ptr = mlx_init();
	if (data.ptr == NULL)
		return (ft_printf_error("Error\ninit MLX failed\n"), 1);
	if (init_little(&data) == false)
		return (destroy_data(&data) + 1);
	data.map_name = argv[1];
	data.map = copy_map(&data);
	if (data.map == NULL)
		return (destroy_data(&data) + 1);
	if (parsing(&data) == false)
		return (destroy_data(&data) + 1);
	start_cub3d(&data);
	destroy_data(&data);
	return (0);
}
