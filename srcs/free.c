/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:52:36 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/03 18:52:36 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while(matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	ft_exit(char *error_msg, t_map *map, int status)
{
	ft_putendl_fd(error_msg, 2);
	if (map)
	{
		if (map->matriz)
		{
			free_matriz(map->matriz);
		}
		if (map->flood)
		{
			free_matriz(map->flood);
		}
		free(map);
	}
	exit(status);
}
