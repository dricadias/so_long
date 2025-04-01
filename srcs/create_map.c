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

// funcao provavelmente temporaria
int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	close(fd);
	return (width);
}

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*open_file;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	open_file = get_next_line(fd);
	height = 0;
	while (open_file) 
	{
		free (open_file);
		open_file = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

char	**create_map(char *file)
{
	int		i;
	char	**matriz;
	int		height = get_height(file);
	int		width = get_width(file);

	matriz = (char **)malloc(sizeof(char *) * (height + 1));
	if (!matriz)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matriz[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!matriz[i])
			return (NULL);
		i++;
	}
	matriz[i] = NULL;
	return (matriz);
}

// pq nao funciona com o width aaaaa
void	fill_map(t_map *map, char *file)
{
	int		x;
	int		fd;
	int		height = get_height(file);
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	x = 0;
	while (x < height)
	{
		line = get_next_line(fd);
		ft_strlcpy(map->matriz[x], line, ft_strlen(line) + 1);
		free(line);
		x++;
	}
	close(fd);
}
