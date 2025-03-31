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

	fd = open(file, O_RDONLY); // verificar depois se abriu bem
	line = get_next_line(fd);
	width = ft_strlen(line) - 1; // tira o '\n'
	free(line);
	close(fd);
	return(width);
}

char	**create_map(char *file)
{
	int		i;
	char	**matrix;
	int		height = read_file(file);
	int		width = get_width(file);

	i = 0;
	matrix = (char **)malloc(sizeof(char *) * height);
	while(i < height)
	{
		matrix[i] = (char *)malloc(sizeof(char) * (width + 1));
		i++;
	}
	return (matrix);
}

void	fill_map(t_map *map, char *file)
{
	int		x;
	//int		y;
	int		fd;
	int		height = read_file(file);
	int		width = get_width(file);
	char	*line;

	fd = open(file, O_RDONLY); // verificar se abriu bem
	x = 0;
	while (x < height)
	{
		line = get_next_line(fd);
		ft_strlcpy(map->matrix[x], line, width + 1); // a primeira linha 
		free(line);									// ta sendo impressa errado
		/* y = 0;
		while(y < width)
		{
			matrix[x][y] = 'F'; assim preenche normal e certo
			y++;
		} */
		x++;
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	t_map	map;
	int		x;
	int		y;
	int		height = read_file(argv[1]);
	int		width = get_width(argv[1]);
	
	map.matrix = create_map(argv[1]);
	fill_map(&map, argv[1]);

	x = 0;
	while(x < height)
	{
		y = 0;
		while(y < width)
		{
			ft_printf("%c", map.matrix[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}