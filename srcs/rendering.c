/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:27:04 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/10 15:54:51 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_img(t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &width, &height);
	game->coll = mlx_xpm_file_to_image(game->mlx, "textures/coll.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->height && game->map->matriz[x])
	{
		y = 0;
		while (y < game->map->width && game->map->matriz[x][y])
		{
			if (game->map->matriz[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, y * TILE, x * TILE);
			else if (game->map->matriz[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, y * TILE, x * TILE);
			else if (game->map->matriz[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->coll, y * TILE, x * TILE);
			else if (game->map->matriz[x][y] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, y * TILE, x * TILE);
			else if (game->map->matriz[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, y * TILE, x * TILE);
			y++;
		}
		x++;
	}
}
