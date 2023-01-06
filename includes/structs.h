/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:37:29 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/05 09:26:30 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define PI 3.14159265358979323846
# define NORTH 1
# define SOUTH 2
# define WEST 4
# define EAST 3

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_pos
{
	int		x;
	int		y;
	char	dir;
}				t_pos;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}				t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
}				t_img;

typedef struct s_cub3d
{
	void	*ptr_img[5];
	void	*ptr;
	void	*win;
	t_color	f;
	t_color	c;
	t_pos	p_pos;
	int		width;
	int		height;
	t_point	char_pos;
	t_point	direct;
	t_img	texture[4];
	int		wallhit;
	t_img	img;
	char	*map_name;
	char	**map;
	int		size_line;
	int		i;
	int		last_elem;
	int		i_first_map;
	int		i_last_map;
	char	**little;
	char	*t_path[7];
	char	*path[7];
}				t_cub3d;

#endif