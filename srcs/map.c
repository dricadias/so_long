/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:02:02 by adias-do          #+#    #+#             */
/*   Updated: 2025/03/31 17:02:07 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_file(char *file)
{
	int ber;

	if (!file)
		return (0);
	ber = ft_strlen(file);
	while(file[ber] != '.')
		ber--;
	if (ft_strncmp(".ber\0", &file[ber], 5) == 0 && file[ber - 1])
		return (1);
	return (0);
}
