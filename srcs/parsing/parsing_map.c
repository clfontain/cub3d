/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:20:43 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/20 15:51:18 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// flood fill algo

#include "../includes/cub3d.h"

bool	valid_char(char c)
{
	if (c != '0' && c != 'N' && c != 'E' && c != 'W' && c != 'S')
		return (false);
	else
		return (true);
}

bool	space_check(char up, char down, char right, char left)
{
	if (valid_char(up) == false && up != '1')
		return (false);
	if (valid_char(down) == false && down != '1')
		return (false);
	if (valid_char(right) == false && right != '1')
		return (false);
	if (valid_char(left) == false && left != '1')
		return (false);
	return (true);
}

bool	check_wall(t_cub3d *data)
{
	int	i;
	int	j;
	int	k;

	i = data->i_first_map;
	k = data->i_last_map;
	while (i < k)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (valid_char(data->map[i][j]) == true)
			{
				if (i == (k - 1) || i == (data->i_first_map) || j == 0)
					return (false);
				if (space_check(data->map[i - 1][j], data->map[i + 1][j]
					, data->map[i][j + 1], data->map[i][j - 1]) == false)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_char(t_cub3d *data)
{
	int	i;
	int	j;

	i = data->i_first_map;
	while (i < (data->i_last_map))
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			if (valid_char(data->map[i][j]) == false
				&& data->map[i][j] != '1'
					&& char_is_isspace(data->map[i][j]) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	parsing_map(t_cub3d *data)
{
	if (check_size_map(data) == false)
		return (ft_printf_error("Error\nEmpty line in map\n"), false);
	if (check_char(data) == false)
		return (ft_printf_error("Error\nInvalid char in map\n"), false);
	if (add_wall(data) == false)
		return (false);
	if (check_wall(data) == false)
		return (ft_printf_error("Error\nWall error\n"), false);
	if (check_map_elem(data) == false)
		return (ft_printf_error("Error\nplayer start error\n"), false);
	return (true);
}
