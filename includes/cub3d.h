/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:25:50 by cfontain          #+#    #+#             */
/*   Updated: 2023/01/03 14:13:06 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "./structs.h"
# include <math.h>

char	**copy_map(t_cub3d *data);
bool	parse_elem(t_cub3d *data);
char	*parse_each_elem(t_cub3d *data, char *little);
bool	parsing(t_cub3d *data);
bool	parsing_path(t_cub3d *data);
bool	parsing_map(t_cub3d *data);
bool	check_map_elem(t_cub3d *data);
int		char_is_isspace(char c);
bool	add_wall(t_cub3d *data);
bool	valid_char(char c);
bool	check_size_map(t_cub3d *data);
bool	check_color(t_cub3d *data);
bool	check_color_format2(char *str, int *i);
bool	convert_color(t_color *color);
bool	start_cub3d(t_cub3d *data);
int		createbaseimg(t_cub3d *data);
int		destroy_data(t_cub3d *data);
void	destroy_data2(t_cub3d *data);

int		find_elem(char **str, char *little, int i);
char	*check_path_color(t_cub3d *data, int i, char *little);
bool	check_all_str(t_cub3d *data, char *str);

#endif
