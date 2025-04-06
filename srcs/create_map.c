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

void	set_values(t_map *map, char *file)
{
	char	*content;

	content = get_content(file);
	is_valid_characters(content);
	map->height = get_height(content);
	map->width = get_width(content);
	map->matriz = ft_split(content, '\n');
	is_map_rectangular(map);
	check_map_walls(map);
	count_map_elements(map);
	free(content);
}

char	*get_content(char *file)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*content;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
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
