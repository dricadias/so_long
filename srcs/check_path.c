/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:28:03 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/06 21:27:10 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player_position(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->matriz[x][y] == 'P')
			{
				map->player_pos.x = x;
				map->player_pos.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || map->flood[x][y] == '1' || map->flood[x][y] == 'F')
		return ;
	map->flood[x][y] = 'F';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

int	is_path_valid(char **fill)
{
	int	x;
	int	y;

	x = 0;
	while(fill[x])
	{
		y = 0;
		while(fill[x][y])
		{
			if (fill[x][y] == 'C' || fill[x][y] == 'E')
				return (ft_printf("caminho impossible"), 0);
			y++;
		}
		x++;
	}
	return (1);
}
