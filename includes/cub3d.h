#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include "../libft/libft.h"
#include <stdbool.h> 
# include "../minilibx-linux/mlx.h"

typedef struct s_cub3d
{
    char *map_name;
    char **map;
    int size_line;
    int i;
    char *little[7];
    char *path[7];
    void *ptr;
}	t_cub3d;

int parsing(char **argv);
char	**parsing_map(t_cub3d *data);
bool parse_elem(t_cub3d *data);


#endif
