/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:19:23 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/22 14:36:40 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	add_to_list(t_cub3d *data, char *str, int i)
{
	int	j;

	j = ft_strlen(data->little[i]);
	while (str[j] != 0 && char_is_isspace(str[j]) == 1)
		j++;
	data->path[i] = ft_strdup(str + j);
	if (data->path[i] == NULL)
		return (false);
	return (true);
}

bool	check_double_name(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 5)
		{
			if (ft_strncmp(data->path[i], data->path[j],
					ft_strlen(data->path[i])) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	init_path(t_cub3d *data)
{
	int	i;
	int	height;
	int	width;

	if (check_double_name(data) == false)
		return (ft_printf_error("Error\nImage wall not different\n")
			, false);
	height = 50;
	width = 50;
	i = 0;
	while (i < 4)
	{
		data->ptr_img[i] = mlx_xpm_file_to_image(data->ptr, data->path[i],
				&height, &width);
		if (data->ptr_img[i] == NULL)
			return (ft_printf_error("Error\nImage Initialization Failed\n")
				, false);
		i++;
	}
	if (check_color(data) == false)
		return (false);
	return (true);
}

bool	parsing_path(t_cub3d *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (ft_strncmp(data->t_path[j], data->little[i],
					ft_strlen(data->little[i])) == 0)
			{
				if (add_to_list(data, data->t_path[j], i) == false)
					return (false);
				break ;
			}
			j++;
		}
		i++;
	}
	if (init_path(data) == false)
		return (false);
	return (true);
}
