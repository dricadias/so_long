/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:43:22 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/18 13:39:42 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_square(t_data *img, int x, int y, int size, int color)
{
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	*mlx;
void	*mlx_win;

int	color_loop(t_data *img)
{
	static int	colors[] = {
		0xFF0000,
		0xFF7F00, 
		0xFFFF00, 
		0x00FF00,
		0x0000FF, 
		0x4B0082, 
		0x8B00FF
	};

	static int index = 0;
	//static int	increment = 0x010000;
	index++;
	if (index >= 7)
		index = 0;
	int color = colors[index];
	/*color += increment;*/
	/*if (color >= 0xFFFFFF)*/
	/*	color = 0x000000;*/
	//printf("loop: %06X\n", color);
	//mlx_clear_window(mlx, mlx_win);
	mlx_destroy_image(mlx, img->img);
	img->img = mlx_new_image(mlx, 7200, 480);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	put_square(img, 310, 190, 100, color);
	mlx_clear_window(mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	usleep(200000);
	return (0);
}

int main(void)
{
	/*void	*mlx;*/
	/*void	*mlx_win;*/
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 480, "hello world!");

	img.img = mlx_new_image(mlx, 720, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	//put_square(&img, 310, 190, 100, 0x00FF0000);
	put_square(&img, 10, 20, 100, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop_hook(mlx, color_loop, &img);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
