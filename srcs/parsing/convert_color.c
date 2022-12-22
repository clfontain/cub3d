/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:29:55 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/21 15:16:32 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_add_zero(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len % 2 == 1)
	{
		str[len] = str[len - 1];
		str[len - 1] = '0';
	}
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	n;
	int	count;

	count = 0;
	i = 0;
	n = 0;
	if (str[i] == '-')
	{
		count++;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = (n * str_base) + (str[i] - 48);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			n = (n * str_base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'z')
			n = (n * str_base) + (str[i] - 'a' + 10);
		i++;
	}
	if (count == 1)
		n = -n;
	return (n);
}

void	put_nbr_str(int nb, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	if (nb < 10)
		str[i] = nb + 48;
	else
		str[i] = nb + 55;
}

void	ft_put_nbr_hex(long int nb, char *str)
{
	if (nb >= 16)
	{
		ft_put_nbr_hex(nb / 16, str);
		ft_put_nbr_hex(nb % 16, str);
	}
	if (nb < 16)
		put_nbr_str(nb, str);
}

bool	convert_color(t_color *color)
{
	char	*str;

	str = ft_calloc(sizeof(char), 10);
	if (str == NULL)
		return (false);
	ft_put_nbr_hex(color->r, str);
	ft_add_zero(str);
	ft_put_nbr_hex(color->g, str);
	ft_add_zero(str);
	ft_put_nbr_hex(color->b, str);
	ft_add_zero(str);
	color->color = ft_atoi_base(str, 16);
	free (str);
	return (true);
}
