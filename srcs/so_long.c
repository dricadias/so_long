/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:41:56 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/01 15:13:07 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	ret;

		ret = valid_file(argv[1]);
		if (ret == 1)
		{
			printf("NL counter: %d\n", get_height(argv[1]));
			//rendering_map(argv[1]);
			t_map	map;
			int		x;
			int		y;
			int		height = get_height(argv[1]);
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
				x++;
			}
			rendering_map();
		}
		else
		{
			ft_putendl_fd("arquivo invalido", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
