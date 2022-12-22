/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tab_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:16:20 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/20 14:19:50 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	destroy_tab_stack(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free (str[i]);
			i++;
		}
	}	
}