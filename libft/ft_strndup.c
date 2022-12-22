/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:15:03 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/20 15:33:51 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != 0 && i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
