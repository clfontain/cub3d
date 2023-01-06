/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:41:07 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/05 12:04:53 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "structs.h"
# include "../libft/libft.h"
# include <math.h>

double	calculdistpercu(t_point a, t_point b, double angle);
t_point	findptwall(t_point start, t_point vdirection, t_cub3d *cub);
t_point	bothlinecross(t_point start, t_point try,
			t_cub3d *cub, t_point vdirect);
t_point	bothlinecross2(t_point start, t_point try,
			t_cub3d *cub, t_point direct);
t_point	singlelinecross(t_point start, t_point try, int cases);
void	raycast_init(t_cub3d *cub);
void	raycast_convert_pos(t_cub3d *cub);
void	raycast_convert_img(t_cub3d *data);
double	calculheight(double dist);
void	rewriteline(t_cub3d *cub, int line, double dist, t_point wall);
t_point	calcray(t_point direct, double angle);
int		select_color(t_cub3d *data, t_point wall, double step);
t_point	create_tex_coord(t_cub3d *data, t_point wall, double step);

int		key_hook(int keycode, t_cub3d *data);
int		ft_do_lateral_mov(t_cub3d *data, int key);
int		ft_do_rotate(t_cub3d *data, int key);
int		ft_do_mov(t_cub3d *data, int key);

t_point	ft_renorm(t_point p);
t_point	create_point(double x, double y);
t_point	addpoint(t_point a, double x, double y); 

#endif