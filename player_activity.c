/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_activity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:50:40 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/27 12:16:57 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initialplr(t_data *vrs)
{
	vrs->player->walkdirection = 0;
	vrs->player->turndirection = 0;
	vrs->player->walkleft = 0;
	vrs->player->walkright = 0;
}

void	walkside(t_data *vrs, int leftright)
{
	float	newplayerx;
	float	newplayery;

	newplayerx = vrs->player->x + cos(vrs->player->rotationangle
	+ leftright * (0.5 * M_PI)) * vrs->player->walkspeed;
	newplayery = vrs->player->y + (sin(vrs->player->rotationangle
	+ leftright * (0.5 * M_PI)) * vrs->player->walkspeed);
	if (!checkwall(vrs, newplayerx, newplayery))
	{
		vrs->player->x = newplayerx;
		vrs->player->y = newplayery;
	}
}

void	walk(t_data *vrs)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;

	movestep = vrs->player->walkdirection * vrs->player->walkspeed;
	newplayerx = vrs->player->x
	+ cos(vrs->player->rotationangle) * movestep;
	newplayery = vrs->player->y
	+ (sin(vrs->player->rotationangle) * movestep);
	if (!checkwall(vrs, newplayerx, newplayery))
	{
		vrs->player->x = newplayerx;
		vrs->player->y = newplayery;
	}
}

void	updateplayerpos(t_data *vrs)
{
	if (vrs->player->turndirection != 0)
	{
		vrs->player->rotationangle += vrs->player->turndirection
		* vrs->player->turnspeed;
	}
	else if (vrs->player->walkleft == 1)
		walkside(vrs, -1);
	else if (vrs->player->walkright == -1)
		walkside(vrs, 1);
	else if (vrs->player->walkdirection != 0)
		walk(vrs);
}
