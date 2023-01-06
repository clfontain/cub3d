/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:02:18 by ccravero          #+#    #+#             */
/*   Updated: 2023/01/05 10:15:48 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point	ft_renorm(t_point p)
{
	double	norm;

	norm = sqrt(p.x * p.x + p.y * p.y);
	while (norm > 1.01 || norm < 0.99)
	{
		if (norm < 0.99)
		{
			p.x += p.x * 0.01;
			p.y += p.y * 0.01;
		}
		else if (norm > 1.01)
		{
			p.x -= p.x * 0.01;
			p.y -= p.y * 0.01;
		}
		norm = sqrt(p.x * p.x + p.y * p.y);
	}
	return (p);
}

t_point	create_point(double x, double y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point	addpoint(t_point a, double x, double y)
{
	a.x = a.x + x;
	a.y = a.y + y;
	return (a);
}
