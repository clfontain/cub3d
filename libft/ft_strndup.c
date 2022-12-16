/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:55 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/16 16:24:46 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strndup(char *s, int len)
{
    int        j;
    char    *dup;

    j = 0;
    dup = ft_calloc(sizeof(char) , (len + 1));
    if (dup == NULL)
        return (0);
    while (s[j])
    {
        dup[j] = s[j];
        j++;
    }

    return (dup);
}