/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:09:43 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/10 17:26:27 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	t_pos	pos;
	char	**matriz;

	matriz = game->map->matriz;
	pos = game->map->player_pos;
	if (matriz[pos.x - 1][pos.y] == '1')
		return ;
	if (matriz[pos.x - 1][pos.y] == 'C')
	{
		matriz[pos.x - 1][pos.y] = '0';
		game->map->c_count--;
	}
	if (matriz[pos.x - 1][pos.y] == 'E')
	{
		if (game->map->c_count == 0)
			exit_game(GAME_WON, game, 0);
		else
			return ;
	}
	matriz[pos.x - 1][pos.y] = 'P';
	matriz[pos.x][pos.y] = '0';
	game->map->player_pos.x -= 1;
	game->map->move_count += 1;
	ft_printf("move count: %d\n", game->map->move_count);
	render_map(game);
}

void	move_left(t_game *game)
{
	t_pos	pos;
	char	**matriz;

	matriz = game->map->matriz;
	pos = game->map->player_pos;
	if (matriz[pos.x][pos.y - 1] == '1')
		return ;
	if (matriz[pos.x][pos.y - 1] == 'C')
	{
		matriz[pos.x][pos.y - 1] = '0';
		game->map->c_count--;
	}
	if (matriz[pos.x][pos.y - 1] == 'E')
	{
		if (game->map->c_count == 0)
			exit_game(GAME_WON, game, 0);
		else
			return ;
	}
	matriz[pos.x][pos.y - 1] = 'P';
	matriz[pos.x][pos.y] = '0';
	game->map->player_pos.y -= 1;
	game->map->move_count += 1;
	ft_printf("move count: %d\n", game->map->move_count);
	render_map(game);
}

void	move_down(t_game *game)
{
	t_pos	pos;
	char	**matriz;

	matriz = game->map->matriz;
	pos = game->map->player_pos;
	if (matriz[pos.x + 1][pos.y] == '1')
		return ;
	if (matriz[pos.x + 1][pos.y] == 'C')
	{
		matriz[pos.x + 1][pos.y] = '0';
		game->map->c_count--;
	}
	if (matriz[pos.x + 1][pos.y] == 'E')
	{
		if (game->map->c_count == 0)
			exit_game(GAME_WON, game, 0);
		else
			return ;
	}
	matriz[pos.x + 1][pos.y] = 'P';
	matriz[pos.x][pos.y] = '0';
	game->map->player_pos.x += 1;
	game->map->move_count += 1;
	ft_printf("move count: %d\n", game->map->move_count);
	render_map(game);
}

void	move_right(t_game *game)
{
	t_pos	pos;
	char	**matriz;

	matriz = game->map->matriz;
	pos = game->map->player_pos;
	if (matriz[pos.x][pos.y + 1] == '1')
		return ;
	if (matriz[pos.x][pos.y + 1] == 'C')
	{
		matriz[pos.x][pos.y + 1] = '0';
		game->map->c_count--;
	}
	if (matriz[pos.x][pos.y + 1] == 'E')
	{
		if (game->map->c_count == 0)
			exit_game(GAME_WON, game, 0);
		else
			return ;
	}
	matriz[pos.x][pos.y + 1] = 'P';
	matriz[pos.x][pos.y] = '0';
	game->map->player_pos.y += 1;
	game->map->move_count += 1;
	ft_printf("move count: %d\n", game->map->move_count);
	render_map(game);
}
