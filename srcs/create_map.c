/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:52:19 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/30 21:52:19 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_width(char *content)
{
	int	width;

	width = 0;
	while (content[width] && content[width] != '\n')
		width++;
	return (width);
}

int	get_height(char *content)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			height++;
		if (content[i] == '\n' && content[i + 1] == '\n')
			return (height);
		if (content[i] == '\n' && content[i + 1] == '\0')
			return (height);
		i++;
	}
	height++;
	return (height);
}

int	count_map_elements(t_map *map)
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
				map->p_count++;
			else if (map->matriz[x][y] == 'C')
				map->c_count++;
			else if (map->matriz[x][y] == 'E')
				map->e_count++;
			y++;
		}
		x++;
	}
	return (1);
}

char	*get_content(char *file, t_game *game)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*content;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game(ERROR_READ, game, 1);
	content = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!content)
			content = ft_strdup(line);
		else
		{
			temp = ft_strjoin(content, line);
			free(content);
			content = temp;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

void	set_values(t_game *game, t_map *map, char *file)
{
	char	*content;

	content = get_content(file, game);
	if (!is_valid_characters(content))
		exit_game(ERROR_INVALID_CHAR, game, 1);
	map->height = get_height(content);
	map->width = get_width(content);
	map->matriz = ft_split(content, '\n');
	map->flood = ft_split(content, '\n');
	count_map_elements(map);
	validate_map(map);
	find_player_position(map);
	fill(map->flood, map->player_pos.x, map->player_pos.y);
	if (is_path_valid(map->flood) == 0)
		exit_game(ERROR_PATH, game, 1);
	free(content);
}
