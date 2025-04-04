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

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->matriz)
		return ;
	i = 0;
	while (map->matriz[i])
	{
		free(map->matriz[i]);
		i++;
	}
	free(map->matriz);
	map->matriz = NULL;
}
