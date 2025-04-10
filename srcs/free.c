/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:52:36 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/03 18:52:36 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	ft_exit(char *error_msg, t_map *map, int status)
{
	ft_putendl_fd(error_msg, 2);
	if (map)
	{
		if (map->matriz)
		{
			free_matriz(map->matriz);
		}
		if (map->flood)
		{
			free_matriz(map->flood);
		}
		free(map);
	}
	exit(status);
}

void	free_images(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->coll)
		mlx_destroy_image(game->mlx, game->coll);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		if (game->map->matriz)
			free_matriz(game->map->matriz);
		if (game->map->flood)
			free_matriz(game->map->flood);
		free(game->map);
	}
	free_images(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	exit_game(char *msg, t_game *game, int status)
{
	ft_putendl_fd(msg, 2);
	free_all(game);
	exit(status);
}
