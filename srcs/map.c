/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:02:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/28 14:44:28 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void read_file(char *file)
{
	int		fd;
	char	*open_file;
	
  fd = open(file, O_RDONLY);
  open_file = get_next_line(fd);
  while (open_file) 
  {
   	ft_printf("%s", open_file);
   	free (open_file);
   	open_file = get_next_line(fd);
  }
	//return (0);
}

int	valid_file(char *file)
{
	int ber;

	if (!file)
		return (1);
	ber = ft_strlen(file);
	while(file[ber] != '.')
		ber--;
	if (ft_strncmp(".ber\0", &file[ber] , 5) == 0 && file[ber - 1])
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	ret;

		ret = valid_file(argv[1]);
		if (ret == 0)
		{
			read_file(argv[1]);
			rendering_map(argv[1]);
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
