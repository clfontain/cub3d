
#include "../includes/cub3d.h"




char	**init_str_map(t_cub3d *data, int size_line)
{
	int	fd2;
	int	i;

	i = 0;
	fd2 = open(data->map_name, O_RDONLY);
	if (fd2 < 0)
		return (ft_printf("Error\nOpen failed\n"), NULL);
	while (i < size_line + 1)
	{
		data->map[i] = get_next_line(fd2);
		i++;
	}
	close(fd2);
	return (data->map);
}

int	count_line(t_cub3d *data)
{
	char	*str;
	int		fd;

	data->size_line = 0;
	fd = open(data->map_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nOpen failed\n"), 1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		data->size_line++;
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	close(fd);
	return (0);
}	

char	**parsing_map(t_cub3d *data)
{
	if (count_line(data) == 1)
		return (NULL);
	data->map = malloc(sizeof(char *) * (data->size_line + 1));
	if (data->map == NULL)
		return (ft_printf("Error\nMalloc Allocation Failed\n"), NULL);
	if (init_str_map(data, data->size_line) == NULL)
		return (destroy_str(data->map), NULL);
	return (data->map);
}