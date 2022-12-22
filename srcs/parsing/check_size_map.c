/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:49:42 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/22 11:57:28 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	str_is_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (char_is_isspace(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	check_last_map(t_cub3d *data)
{
	size_t	j;
	int		i;

	i = (data->i_first_map + 1);
	while (i < data->size_line)
	{
		if (str_is_isspace(data->map[i]) == true)
			break ;
		i++;
	}
	data->i_last_map = i;
	while (i < data->size_line)
	{
		j = 0;
		while (data->map[i][j] && char_is_isspace(data->map[i][j]) == 1)
			j++;
		if (j != ft_strlen(data->map[i]))
			break ;
		i++;
	}
	if (i != data->size_line)
		return (false);
	return (true);
}

bool	check_first_map(t_cub3d *data)
{
	size_t	j;
	int		i;

	i = (data->last_elem + 1);
	while (i < data->size_line)
	{
		j = 0;
		while (data->map[i][j] && char_is_isspace(data->map[i][j]) == 1)
			j++;
		if (j != ft_strlen(data->map[i]))
			break ;
		i++;
	}
	if (i == data->size_line)
		return (false);
	data->i_first_map = i;
	return (true);
}

bool	check_size_map(t_cub3d *data)
{
	if (check_first_map(data) == false)
		return (false);
	if (check_last_map(data) == false)
		return (false);
	return (true);
}
