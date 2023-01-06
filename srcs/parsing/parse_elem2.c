/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:44:00 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/03 13:44:56 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*parse_each_elem_color(t_cub3d *data, char *little)
{
	char	*tmp;
	int		i;
	int		res;

	i = 0;
	i = find_elem(data->map, little, i);
	if (i == -1)
		return (NULL);
	else
	{
		tmp = check_path_color(data, i, little);
	}
	if ((i + 1) != data->size_line)
	{
		res = find_elem(data->map, little, (i + 1));
		if (res != -1)
			return (free(tmp), NULL);
	}
	if (i > data->last_elem)
		data->last_elem = i;
	return (tmp);
}

bool	parse_elem(t_cub3d *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->t_path[i] = parse_each_elem(data, data->little[i]);
		if (data->t_path[i] == NULL)
			return (ft_printf_error("Error\nElements parsing\n"), false);
		i++;
	}
	while (i < 6)
	{
		data->t_path[i] = parse_each_elem_color(data, data->little[i]);
		if (data->t_path[i] == NULL)
			return (ft_printf_error("Error\nElements parsing\n"), false);
		i++;
	}
	i = 0;
	while (i < data->last_elem)
	{
		if (check_all_str(data, data->map[i]) == false)
			return (ft_printf_error("Error\nElements parsing\n"), false);
		i++;
	}
	return (true);
}
