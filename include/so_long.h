/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:08:53 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/27 12:09:45 by adias-do         ###   ########.fr       */
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

typedef struct s_long
{
	int						x;
	int						y;
}	t_long;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// functions
int	valid_file(char *file);
void read_file(char *file);

// mlx
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_square(t_data *img, int x, int y, int size, int color);
void	rendering_map(char *file);
#endif
