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

// dando leak aqui. fazer uma funcao pra limpar a matriz
char	**create_map(t_map *map, char *file)
{
	int		i;
	map->height = get_height(file);
	map->width = get_width(file);

	map->matriz = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->matriz)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map->matriz[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!map->matriz[i])
		{
			while (i > 0)
			{
				free(map->matriz[i - 1]);
				i--;
			}
			free(map->matriz);
			return (NULL);
		}
		i++;
	}
	map->matriz[i] = NULL;
	return (map->matriz);
}

// pq nao funciona com o width aaaaa
// att agora ta funcionando quando chamo com a struct ????
void	fill_map(t_map *map, char *file)
{
	int		x;
	int		fd;
	char	*line;
	map->height = get_height(file); // pq EU TENHO QUE FAZER ISSO DE NOVOOOOOOOO

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	x = 0;
	while (x < map->height)
	{
		line = get_next_line(fd);
		ft_strlcpy(map->matriz[x], line, map->width + 1); //ft_strlen(line) + 1
		free(line);
		x++;
	}
	close(fd);
}
