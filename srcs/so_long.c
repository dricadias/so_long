/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:41:56 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/10 19:50:35 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		exit_game(ERROR_ARGS, game, EXIT_FAILURE);
	if (!is_ber_file(argv[1]))
		exit_game(ERROR_FILE, game, EXIT_FAILURE);
	game = init_game();
	if (!game)
		return (EXIT_FAILURE);
	set_values(game, game->map, argv[1]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * TILE, \
		game->map->height * TILE, "so_long");
	mlx_key_hook(game->win, handle_input, game);
	load_img(game);
	render_map(game);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
