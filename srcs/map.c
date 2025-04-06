/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:02:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/06 16:14:56 by adias-do         ###   ########.fr       */
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

int	is_map_rectangular(char **matriz)
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
			return (0);
		i++;
	}
	return (1);
}

int	check_map_walls(char **matriz, int height, int width)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < width)
	{
		if (matriz[0][y] != '1' || matriz[height - 1][y] != '1')
			return (0);
		y++;
	}
	while (x < height)
	{
		if (matriz[x][0] != '1' || matriz[x][width - 1] != '1')
			return (0);
		x++;
	}
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
