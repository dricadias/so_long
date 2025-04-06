/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:08:53 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/06 21:05:51 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# define TILE_SIZE 50

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		width;
	int		height;
	int		p_count;
	int		c_count;
	int		e_count;
	char	**matriz;
	char	**flood;
	t_pos	player_pos;
}	t_map;

// struct do teste
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_coll;
	void	*img_exit;
	t_map	*map;
}	t_game;

// validation
int		is_ber_file(char *file);
int		is_valid_characters(char *content);
int		is_map_rectangular(t_map *map);
int		check_map_walls(t_map *map);
int		count_map_elements(t_map *map);

// utils
void	find_player_position(t_map *map);

// free
void	free_map(t_map *map);

// matriz
int		get_width(char *content);
int		get_height(char *content);
char	*get_content(char *file);
void	set_values(t_map *map, char *file);

// mlx
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	rendering_map(t_game *game);
void	load_img(t_game *game);

#endif
