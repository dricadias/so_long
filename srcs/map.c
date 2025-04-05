/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:02:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/05 19:38:26 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	is_valid_characters(char *content)
{
	int	i;

	i = 0;

	while (content[i])
	{
		if (content[i] != '0' && content[i] != '1' && content[i] != 'P' 
			&& content[i] != 'E' && content[i] != 'C' && content[i] != '\n')
		{
			return ((void)ft_printf("map isnt valid\n"), exit(EXIT_FAILURE));
		}
		i++;
	}
	return ((void)ft_printf("map is valid\n"));
}

int	is_ber_file(char *file)
{
	int	ber;

	if (!file)
		return (0);
	ber = ft_strlen(file);
	while (file[ber] != '.')
		ber--;
	if (ft_strncmp(".ber\0", &file[ber], 5) == 0 && file[ber - 1])
		return (1);
	return (0);
}
