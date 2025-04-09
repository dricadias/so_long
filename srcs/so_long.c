/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:41:56 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/09 18:13:48 by adias-do         ###   ########.fr       */
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
	t_map	map;
	t_game	game;

	if (argc != 2)
		return (ft_printf(ERROR_ARGS), EXIT_FAILURE);
	is_ber_file(argv[1]);
	game.mlx = mlx_init();
	game.map = malloc(sizeof(t_map));
	set_values(game.map, argv[1]);
	game.mlx_win = mlx_new_window(game.mlx, game.map->width * TILE_SIZE, game.map->height * TILE_SIZE, "so_long");
	mlx_key_hook(game.mlx_win, handle_input, &game);
	load_img(&game);
	render_map(&game);
	mlx_loop(game.mlx);
	ft_exit("sucesso", &map, 0);
	return (0);
}
