/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:59:52 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/22 12:10:57 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*check_path_color(t_cub3d *data, int i, char *little)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnstr(data->map[i], little, ft_strlen(data->map[i]));

	tmp2 = ft_strndup(tmp, ft_strlen(tmp) - 1);
	if (tmp2 == NULL)
		return (false);
	return (tmp2);
}

char	*check_path_elem(t_cub3d *data, int i, char *little)
{
	char	*tmp;
	char	*tmp2;
	size_t	k;

	tmp = ft_strnstr(data->map[i], little, ft_strlen(data->map[i]));
	i = ft_strlen(little);
	while (tmp[i] != 0 && char_is_isspace(tmp[i]) == 1)
		i++;
	while (tmp[i] != 0 && char_is_isspace(tmp[i]) == 0)
		i++;
	k = i;
	while (tmp[k] != 0 && char_is_isspace(tmp[k]) == 1)
		k++;
	if (k != (ft_strlen(tmp)))
		return (false);
	tmp2 = ft_strndup(tmp, i);
	if (tmp2 == NULL)
		return (false);
	return (tmp2);
}

bool	check_all_str(t_cub3d *data, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && char_is_isspace(str[i]) == 1)
		i++;
	if (i == ft_strlen(str))
		return (true);
	while (j < 6)
	{
		if (ft_strncmp(str + i, data->little[j],
				ft_strlen(data->little[j])) != 0)
			j++;
		else
		{
			return (true);
		}
	}
	return (false);
}

int	find_elem(char **str, char *little, int i)
{
	char	*tmp;

	while (str[i] != NULL)
	{
		tmp = ft_strnstr(str[i], little, ft_strlen(str[i]));
		if (tmp != NULL)
			return (i);
		i++;
	}
	return (-1);
}

char	*parse_each_elem(t_cub3d *data, char *little)
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
		tmp = check_path_elem(data, i, little);
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
	//ft_printab(data->t_path);
	i = 0;
	while (i < data->last_elem)
	{
		if (check_all_str(data, data->map[i]) == false)
			return (ft_printf_error("Error\nElements parsing\n"), false);
		i++;
	}
	return (true);
}
