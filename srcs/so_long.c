/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:41:56 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/03 23:36:01 by adias-do         ###   ########.fr       */
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
	int		ret;
	t_map	map;

	if (argc == 2)
	{
		ret = valid_file(argv[1]);
		if (ret == 1)
		{
			//print_map(map);
			t_game game;
			
			game.mlx = mlx_init();
			game.map = malloc(sizeof(t_map));
			set_values(game.map, argv[1]);
			game.mlx_win = mlx_new_window(game.mlx, game.map->width * TILE_SIZE, game.map->height * TILE_SIZE, "so_long");
			load_img(&game);
			rendering_map(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			ft_putendl_fd("arquivo invalido", 2);
			exit(EXIT_FAILURE);
		}
	}
	free_map(&map);
	return (0);
}
