/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:02:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/27 12:11:16 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	check_walls(char *file)
{
	char *line = get_next_line(0);
	while(line)
	{
		if (ft_strncmp(line, file, 10))
		{
			ft_putendl_fd("nao tem barreira", 2);
			return (1);
		}
		line = get_next_line(0);
	}
	return (0);
}

int	read_file(char *file)
{
	int ber;

	if (!file)
		return (1);
	ber = ft_strlen(file);
	while(file[ber] != '.')
		ber--;
	if (ft_strncmp(".ber\0", &file[ber] , 5) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	ret;

		ret = read_file(argv[1]);
		if (ret == 0)
		{
			check_walls(argv[1]);
		}
		else
		{
			ft_putendl_fd("arquivo invalido", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
		return (0);
}
