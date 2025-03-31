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
int		get_width(char *file)
{
	int	fd;
	int	width;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	width = ft_strlen(line) - 1; // tira o '\n'
	free(line);
	close(fd);
	return(width);
}

char	**create_map(char *file)
{
	int		i;
	char	**matriz;
	int		height = read_file(file);
	int		width = get_width(file);

	matriz = (char **)malloc(sizeof(char *) * (height + 1));
	if (!matriz)
		return (NULL);
	i = 0;
	while(i < height)
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
	//int		y;
	int		fd;
	int		height = read_file(file);
	//int		width = get_width(file);
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

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		(void)argc;
		t_map	map;
		int		x;
		int		y;
		int		height = read_file(argv[1]);
		int		width = get_width(argv[1]);
		
		map.matriz = create_map(argv[1]);
		fill_map(&map, argv[1]);

		x = 0;
		while(x < height)
		{
			y = 0;
			while(y < width)
			{
				ft_printf("%c", map.matriz[x][y]);
				y++;
			}
			ft_printf("\n");
			x++;
		}
	}
}