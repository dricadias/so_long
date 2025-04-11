/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:08:53 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/11 12:24:54 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# define TILE 50

# define ERROR_ARGS "Error: invalid amount of arguments."
# define ERROR_FILE "Error: invalid file."
# define ERROR_READ "Error: invalid file read."
# define ERROR_INVALID_CHAR "Error: map has invalid chars."
# define ERROR_INVALID_WALL "Error: map must be surrounded by walls."
# define ERROR_NEWLINE "Error: map has new lines."
# define ERROR_RECTANGLE "Error: map must be rectangular."
# define ERROR_PLAYER "Error: map can only have one player."
# define ERROR_COLL "Error: map needs at least 1 collectible."
# define ERROR_EXIT "Error: map can only have one exit."
# define ERROR_PATH "Error: invalid path."
# define ERROR_IMG "Error: image failed to load."
# define GAME_WON "Well done! You've won the game!"

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
	int		move_count;
	char	**matriz;
	char	**flood;
	t_pos	player_pos;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*coll;
	void	*exit;
	t_map	*map;
}	t_game;

// init structs
t_map	*init_map(void);
t_game	*init_game(void);

// validation
int		is_ber_file(char *file);
int		is_valid_characters(char *content);
int		is_map_rectangular(t_map *map);
int		check_map_walls(t_map *map);
int		count_map_elements(t_map *map);
int		is_path_valid(char **fill);
int		validate_map(t_game *game, t_map *map);

// utils
void	find_player_position(t_map *map);
void	fill(char **flood, int x, int y);

// free
void	free_matriz(char **matriz);
void	ft_exit(char *error_msg, t_map *map, int status);
void	free_images(t_game *game);
void	free_all(t_game *game);
void	exit_game(char *msg, t_game *game, int status);

// matriz
int		get_width(char *content);
int		get_height(t_game *game, char *content);
char	*get_content(char *file, t_game *game);
void	set_values(t_game *game, t_map *map, char *file);

// mlx
void	render_map(t_game *game);
void	load_img(t_game *game);
	// render window
void	render_wall(t_game *game);
void	render_floor(t_game *game);
void	render_coll(t_game *game);
void	render_player(t_game *game);
void	render_exit(t_game *game);

// mlx moves
int		handle_input(int keycode, t_game *game);

// moves
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);

#endif