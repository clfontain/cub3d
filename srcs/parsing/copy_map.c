/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:56:45 by cfontain          #+#    #+#             */
/*   Updated: 2023/01/03 12:17:06 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_map_name(t_cub3d *data)
{
	if (ft_strlen(data->map_name) == 4)
		return (false);
	if (ft_strncmp(data->map_name + (ft_strlen(data->map_name) - 4)
			, ".cub", 4) != 0)
		return (false);
	return (true);
}

char	**init_str_map(t_cub3d *data, int size_line)
{
	int	fd2;
	int	i;

	i = 0;
	fd2 = open(data->map_name, O_RDONLY);
	if (fd2 < 0)
		return (ft_printf("Error\nOpen failed\n"), NULL);
	while (i < size_line + 1)
	{
		data->map[i] = get_next_line(fd2);
		i++;
	}
	close(fd2);
	return (data->map);
}

int	count_line(t_cub3d *data)
{
	char	*str;
	int		fd;

	data->size_line = 0;
	fd = open(data->map_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nOpen failed\n"), 1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		data->size_line++;
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	close(fd);
	return (0);
}

char	**copy_map(t_cub3d *data)
{
	if (check_map_name(data) == false)
		return (ft_printf_error("Error\nInvalid map name\n"), NULL);
	if (count_line(data) == 1)
		return (NULL);
	data->map = ft_calloc(sizeof(char *), (data->size_line + 1));
	if (data->map == NULL)
		return (NULL);
	if (init_str_map(data, data->size_line) == NULL)
		return (destroy_str(data->map), NULL);
	return (data->map);
}
