/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:27:04 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/28 15:01:11 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// renderizar o mapa na tela
// colocar as imagens em cada posição (chão, parede, jogador, saída, etc.).
// desenhar apenas blocos coloridos por agora.


/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)*/
/*{*/
/*	char	*dst;*/
/**/
/*	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));*/
/*	*(unsigned int*)dst = color;*/
/*}*/
/**/
/*void	put_square(t_data *img, int x, int y, int size, int color)*/
/*{*/
/*	int	i;*/
/*	int j;*/
/**/
/*	i = 0;*/
/*	while (i < size)*/
/*	{*/
/*		j = 0;*/
/*		while (j < size)*/
/*		{*/
/*			my_mlx_pixel_put(img, x + i, y + j, color);*/
/*			j++;*/
/*		}*/
/*		i++;*/
/*	}*/
/*}*/

/*void rendering_map(char *file)*/
/*{*/
/*	void	*mlx;*/
/*	void	*mlx_win;*/
/*	t_data	img;*/
/*	t_long	pos_y;*/
/*	t_long	pos_x;*/
/**/
/*	pos_x.x = 0;*/
/*	pos_y.y = 0;*/
/*	mlx = mlx_init();*/
/*	mlx_win = mlx_new_window(mlx, 1280, 720, "so_long");*/
/**/
/*	img.img = mlx_new_image(mlx, 1280, 720);*/
/*	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);*/
/*	while(*file)*/
/*	{*/
/*		put_square(&img, pos_x.x, pos_y.y, 75, 0x00999999);*/
/*		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);*/
/*		pos_x.x += 75;*/
/*		//pos_y.y += 100;*/
/*		file++;*/
/*	}*/
/*	mlx_loop(mlx);*/
/*}*/

void rendering_map(char *file)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*path = "../map.ber";
	int		img_width;
	int		img_height;
	t_long	pos_y;
	t_long	pos_x;

	pos_x.x = 0;
	pos_y.y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "so_long");

	img = mlx_xpm_to_image(mlx, path,	&img_width, &img_height);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while(*file)
	{
		//put_square(&img, pos_x.x, pos_y.y, 75, 0x00999999);
		mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
		pos_x.x += 75;
		//pos_y.y += 100;
		file++;
	}
	mlx_loop(mlx);
}
