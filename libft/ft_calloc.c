/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:55 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/20 15:35:20 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb != 0 && size > (size_t) -1 / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (ft_printf_error("Error\nCalloc error"), NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
