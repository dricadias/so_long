/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:27:04 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/09 17:58:41 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_img(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/quadrado_cinza50.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/quadrado_verde.xpm", &width, &height);
	game->img_coll = mlx_xpm_file_to_image(game->mlx, "textures/quadrado_amarelo.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/quadrado_azul.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/quadrado_vermelho.xpm", &width, &height);
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
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_wall, y * TILE_SIZE, x * TILE_SIZE);
			else if (game->map->matriz[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor, y * TILE_SIZE, x * TILE_SIZE);
			else if (game->map->matriz[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_coll, y * TILE_SIZE, x * TILE_SIZE);
			else if (game->map->matriz[x][y] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player, y * TILE_SIZE, x * TILE_SIZE);
			else if (game->map->matriz[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_exit, y * TILE_SIZE, x * TILE_SIZE);
			y++;
		}
		x++;
	}
}
