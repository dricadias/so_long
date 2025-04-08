/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:02:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/08 18:03:06 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_characters(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '0' && content[i] != '1' && content[i] != 'P'
			&& content[i] != 'E' && content[i] != 'C' && content[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_rectangular(t_map *map)
{
	int	i;
	int	len;
	int	len2;

	i = 0;
	len = ft_strlen(map->matriz[0]);
	while (map->matriz[i])
	{
		len2 = ft_strlen(map->matriz[i]);
		if (len != len2)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->width)
	{
		if (map->matriz[0][y] != '1' || map->matriz[map->height - 1][y] != '1')
			return (0);
		y++;
	}
	while (x < map->height)
	{
		if (map->matriz[x][0] != '1' || map->matriz[x][map->width - 1] != '1')
			return (0);
		x++;
	}
	return (1);
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

/* int	validate_map(t_map *map)
{
	if (!check_map_walls(map))
		return (ft_printf((ERROR_INVALID_WALL), 0));
	else if (!check_map_elements(map))
		return (0);
	else if (!is_path_valid(map->flood))
		return (ft_printf((ERROR_PATH), 0));
	return (1);
}*/

int	check_map_elements(t_map *map)
{
	if (map->p_count != 1)
		return (ft_printf(ERROR_PLAYER), 0);
	if (map->c_count < 1)
		return (ft_printf(ERROR_COLL), 0);
	if (map->e_count != 1)
		return (ft_printf(ERROR_EXIT), 0);
	return (1);
}

int	is_ber_file(char *file)
{
	int	ber;

	if (!file)
		return (0);
	ber = ft_strlen(file);
	while (file[ber] != '.')
		ber--;
	if (ft_strncmp(".ber\0", &file[ber], 5) == 0 && file[ber - 1])
		return (1);
	return (0);
}
