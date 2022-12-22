/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:25:50 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/22 14:43:59 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"

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
	int	color; // la variable int color convertie 
}				t_color;

typedef struct s_cub3d
{
	// Core
	void	*ptr_img[5]; //les pointeurs des 4 images initialise avec la fonction minilix filo to image
	void	*ptr; // le ptr mlx_init
	void	*win; // le ptr mlx_win
	t_color	f; // FLOOR une struct color qui contient l'int color converti pret a etre envoye a la fonction  mlx_pixel_put
	t_color	c; // CEILLING une struct color qui contient l'int color converti pret a etre envoye a la fonction  mlx_pixel_put
	t_pos	p_pos; // Une struct contenant la position de depart du joueur x, y ainsi qu'un char dir = orientation du joueur (N, S, W, E) 

	// Parsing
	char	*map_name;
	char	**map; // le parsing de la map, les espaces vides sont remplies de X et la carte est converti a une forme rectangulaire
	int		size_line; // taille de la map + les elements
	int		i;
	int		last_elem; // position du dernier element 
	int		i_first_map; // position de la premiere ligne de la map
	int		i_last_map; // position de la derniere ligne de la map
	char	**little; // chaine tmp pour parsing
	char	*t_path[7]; // chaine tmp pour parsing
	char	*path[7]; // chaine tmp pour parsing
}				t_cub3d;

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
bool	convert_color(t_color *color);
bool	start_cub3d(t_cub3d *data);
#endif
