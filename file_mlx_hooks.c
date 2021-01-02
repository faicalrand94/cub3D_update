/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mlx_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:21:58 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/27 11:48:28 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	func_key(int keycode, t_data *vrs)
{
	if (keycode == 123)
		vrs->player->turndirection = -1;
	if (keycode == 124)
		vrs->player->turndirection = 1;
	if (keycode == 1)
		vrs->player->walkdirection = -1;
	if (keycode == 13)
		vrs->player->walkdirection = 1;
	if (keycode == 0)
		vrs->player->walkleft = 1;
	if (keycode == 2)
		vrs->player->walkright = -1;
}

int		move_player(int keycode, t_data *vrs)
{
	mlx_clear_window(vrs->mlx, vrs->mlx_win);
	mlx_destroy_image(vrs->mlx, vrs->img);
	initialplr(vrs);
	func_key(keycode, vrs);
	call_functions(vrs);
	return (0);
}

int		esc(int keycode, t_data *vrs)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vrs->mlx, vrs->mlx_win);
		freexit(vrs);
		exit(0);
	}
	return (0);
}

int		redbutton(t_data *vrs)
{
	mlx_destroy_window(vrs->mlx, vrs->mlx_win);
	freexit(vrs);
	exit(0);
	return (0);
}

void	my_mlx_hooks(t_data *vrs)
{
	mlx_hook(vrs->mlx_win, 2, 0, move_player, vrs);
	mlx_key_hook(vrs->mlx_win, esc, vrs);
	mlx_hook(vrs->mlx_win, 17, 0, redbutton, vrs);
	mlx_loop(vrs->mlx);
}
