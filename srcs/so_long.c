/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:41:56 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/10 17:27:26 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_map map)
{
	int		x;
	int		y;

	x = 0;
	while (x < map.height && map.matriz[x])
	{
		y = 0;
		while (y < map.width && map.matriz[x][y])
		{
			ft_printf("%c", map.matriz[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		exit_game(ERROR_ARGS, game, EXIT_FAILURE);
	is_ber_file(argv[1]);
	game = init_game();
	if (!game)
		return (EXIT_FAILURE);
	game->mlx = mlx_init();
	set_values(game->map, argv[1]);
	game->win = mlx_new_window(game->mlx, game->map->width * TILE, \
		game->map->height * TILE, "so_long");
	mlx_key_hook(game->win, handle_input, game);
	load_img(game);
	render_map(game);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
