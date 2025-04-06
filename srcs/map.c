/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:02:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/06 06:28:17 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// arrumar os returns depois
void	is_valid_characters(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '0' && content[i] != '1' && content[i] != 'P'
			&& content[i] != 'E' && content[i] != 'C' && content[i] != '\n')
		{
			return ((void)ft_printf("map isnt valid\n"), exit(EXIT_FAILURE));
		}
		i++;
	}
	return ((void)ft_printf("map is valid\n"));
}

// arrumar os returns depois
void	is_map_rectangular(char **matriz)
{
	int	i;
	int	len;
	int	len2;

	i = 0;
	len = ft_strlen(matriz[0]);
	while (matriz[i])
	{
		len2 = ft_strlen(matriz[i]);
		if (len != len2)
			return ((void)ft_printf("map isnt rectangular\n"), exit(EXIT_FAILURE));
		i++;
	}
	return ((void)ft_printf("map is rectangular\n"));
}

// arrumar os returns depois
void	check_map_walls(char **matriz, int height, int width)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < width)
	{
		if (matriz[0][y] != '1' || matriz[height - 1][y] != '1')
			return ((void)ft_printf("map isnt surrounded by walls\n"), exit(EXIT_FAILURE));
		y++;
	}
	while (x < height)
	{
		if (matriz[x][0] != '1' || matriz[x][width - 1] != '1')
			return ((void)ft_printf("map isnt surrounded by walls2\n"), exit(EXIT_FAILURE));
		x++;
	}
	return ((void)ft_printf("map is surrounded by walls\n"));
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
