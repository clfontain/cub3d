/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:15:03 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/22 14:36:09 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_color_range(char *str, t_color *color)
{
	bool res;

	res = true;
	char **tmp;
	tmp = ft_split(str, ',');
	if (tmp == NULL)
		return (false);
	color->r = ft_atoi(tmp[0]);
	if (color->r < 0 || color->r > 255)
		res = false;
	color->g = ft_atoi(tmp[1]);
	if (color->g < 0 || color->g > 255)
		res = false;
	color->b = ft_atoi(tmp[2]);
	if (color->b < 0 || color->b > 255)
		res = false;
	destroy_str(tmp);
	return (res);
}

bool	check_color_format(char *str, t_color *color)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	if (ft_isdigit(str[0]) != 1)
		return (ft_printf_error("Error\nFormat color\n"), false);
	while (str[j] != 0)
	{
		if (ft_isdigit(str[j]) != 1 && str[j] != ',' && str[j] != ' ')
			return (ft_printf_error("Error\nFormat color\n"), false);
		j++;
	}
	j = 0;
	while (str[j] != 0)
	{
		while (char_is_isspace(str[j]) == 1)
			j++;
		if (ft_isdigit(str[j]) == 1)
		{
			while (ft_isdigit(str[j]) == 1)
			j++;
		}
		else
			return (ft_printf_error("%dError\nFormat color\n", j), false);
		while (char_is_isspace(str[j]) == 1)
			j++;
		if (str[j] == ',' && i != 2)
			i++;
		else if (str[j] != 0)
			return (ft_printf_error("%dError\nFormat color\n", j), false);
		if (str[j] != 0)
			j++;
	}
	if (i != 2 )
		return (ft_printf_error("Error\nfFormat color\n"), false);
	if (check_color_range(str, color) == false)
		return (ft_printf_error("Error\nRange color\n"), false);
	return (true);
}

bool	check_color(t_cub3d *data)
{
	if (check_color_format(data->path[4], &data->f) == false)
		return (false);
	if (check_color_format(data->path[5], &data->c) == false)
		return (false);
	return (true);
}
