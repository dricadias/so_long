/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:27:15 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/10 17:31:09 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->matriz = NULL;
	map->flood = NULL;
	map->width = 0;
	map->height = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->move_count = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	return (map);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->win = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->player = NULL;
	game->coll = NULL;
	game->exit = NULL;
	game->map = init_map();
	if (!game->map)
	{
		free(game);
		return (NULL);
	}
	return (game);
}
