/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:37:29 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/28 16:58:06 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		size;

	size = ft_strlen(s);
	i = 0;
	str = ft_calloc(sizeof(char), (size + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
