
#include "../includes/cub3d.h"

int	char_is_isspace(char c)
{
	if (c >= 9 && c <= 11)
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}


bool	check_path_elem(t_cub3d *data, int i, char *little)
{
	char *tmp;
	int j;

	j = ft_strlen(little);
	tmp = ft_strnstr(data->map[i], little, ft_strlen(data->map[i]));
	while (tmp[j] != 0 && char_is_isspace(tmp[j]) == 1)
		j++;
	printf("%d\n", j);
	i = j;
	while (tmp[i] != 0 && char_is_isspace(tmp[i]) == 0)
		i++;
	printf("%d\n", i);
	char * tmp2 = ft_strndup(tmp + j, (i - j));
	printf("%s\n", tmp2);
	return (true);
}

int find_elem(char **str, char *little, int i)
{
	char *tmp;

	while (str[i] != NULL)
	{
		tmp = ft_strnstr(str[i], little, ft_strlen(str[i]));
		if (tmp != NULL)
			return (i);
		i++;
	}
	return (-1);
}

bool parse_each_elem(t_cub3d *data, char *little)
{
	int i;
	i = 0;

	i = find_elem(data->map, little, i);
	if (i == -1)
		return (false);
	else
	{
		check_path_elem(data, i, little);
	}
	if ((i + 1) != data->size_line)
	{
		i = find_elem(data->map, little, (i + 1));
		if (i != -1)
			return (false);
	}
	return (true);
}

bool parse_elem(t_cub3d *data)
{
	int i;
   

	i = 0;
	while (i < 6)
	{
		if (parse_each_elem(data, data->little[i]) == false)
			return (false);
		i++;
	}
	
	return (true);
}