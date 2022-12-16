/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:14:57 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/16 16:06:56 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

void	destroy_data(t_cub3d *data)
{
	if (data->map != NULL)
		destroy_str(data->map);
}

void	init_little(t_cub3d *data)
{
	data->little[0] = "NO";
	data->little[1] = "SO";
	data->little[2] = "WE";
	data->little[3] = "EA";
	data->little[4] = "F";
	data->little[5] = "C";

}


int main(int argc, char **argv, char **env)
{
	t_cub3d data;


	if (argc != 2)
		return (0);
	(void)env;
	ft_memset(&data, 0, sizeof(data));
	init_little(&data);
	data.ptr = mlx_init();
	data.map_name = argv[1];
	data.map = parsing_map(&data);
	ft_printab(data.map);
	printf("%d\n", parse_elem(&data));
	destroy_data(&data);
	return (0);
}



/*

ls < |>




*/