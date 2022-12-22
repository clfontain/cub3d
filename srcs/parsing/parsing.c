/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:07:32 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/22 11:56:50 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	parsing(t_cub3d *data)
{
	if (parse_elem(data) == false)
		return (false);
	if (parsing_path(data) == false)
		return (false);
	if (parsing_map(data) == false)
		return (false);
	if (convert_color(&data->f) == false)
		return (false);
	if (convert_color(&data->c) == false)
		return (false);
	return (true);
}
