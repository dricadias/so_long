/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:50:13 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/11 12:38:02 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_img(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/f.xpm", &w, &h);
	game->coll = mlx_xpm_file_to_image(game->mlx, "textures/coll.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/p.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	if (!game->wall || !game->floor || !game->exit
		|| !game->player || !game->coll)
		exit_game(ERROR_IMG, game, 1);
}

void	render_map(t_game *game)
{
	render_wall(game);
	render_coll(game);
	render_floor(game);
	render_player(game);
	render_exit(game);
}
