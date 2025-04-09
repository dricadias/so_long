/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adias-do <adias-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:43:05 by adias-do          #+#    #+#             */
/*   Updated: 2025/04/09 18:43:41 by adias-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int handle_input(int keycode, t_game *game)
{
/* 	if (keycode == XK_Escape)
		close_window(); */
	if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		move_up(game);
	if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		move_left(game);
	if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		move_down(game);
	if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		move_right(game);
	return (0);
}