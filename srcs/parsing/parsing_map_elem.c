/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:56:51 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/20 16:22:32 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_big_str(t_cub3d *data)
{
	int		i;
	size_t	len;

	i = data->i_first_map;
	len = 0;
	while (i < (data->i_last_map))
	{
		if (len < ft_strlen(data->map[i]))
			len = ft_strlen(data->map[i]);
		i++;
	}
	return (len);
}

bool	add_wall_square(t_cub3d *data, int len)
{
	char	*str;
	int		i;
	int		j;

	i = data->i_first_map;
	while (i < (data->i_last_map))
	{
		str = ft_strndup(data->map[i], len);
		j = ft_strlen(str) - 1;
		if (str == NULL)
			return (false);
		while (j < (len - 1))
		{
			str[j] = 'X';
			j++;
		}
		str[j] = '\n';
		free (data->map[i]);
		data->map[i] = str;
		i++;
	}
	return (true);
}

bool	add_wall(t_cub3d *data)
{
	int	i;
	int	j;
	int	len;

	len = find_big_str(data);
	i = data->i_first_map;
	while (i < (data->i_last_map))
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (char_is_isspace(data->map[i][j]) == 1
				&& data->map[i][j] != '\n')
			{
				data->map[i][j] = 'X';
			}
			j++;
		}
		i++;
	}
	if (add_wall_square(data, len) == false)
		return (false);
	return (true);
}

bool	check_map_elem(t_cub3d *data)
{
	int	i;
	int	j;
	int	trigg;

	trigg = 0;
	i = data->i_first_map;
	while (i < (data->i_last_map))
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (valid_char(data->map[i][j]) == true && data->map[i][j] != '0')
			{
				data->p_pos.x = j;
				data->p_pos.y = i;
				data->p_pos.dir = data->map[i][j];
				trigg++;
			}
			j++;
		}
		i++;
	}
	if (trigg != 1)
		return (false);
	return (true);
}
