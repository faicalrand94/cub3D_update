/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:49:01 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/28 16:19:14 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	distbtnpts(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	rightray(t_data *vrs, int iray)
{
	if (vrs->rayvars.vhd < vrs->rayvars.hhd)
	{
		vrs->ray[iray]->distance = vrs->rayvars.vhd;
		vrs->ray[iray]->wallhitx = vrs->rayvars.vwhx;
		vrs->ray[iray]->wallhity = vrs->rayvars.vwhy;
		vrs->ray[iray]->washitvertical = 1;
	}
	else
	{
		vrs->ray[iray]->distance = vrs->rayvars.hhd;
		vrs->ray[iray]->wallhitx = vrs->rayvars.hwhx;
		vrs->ray[iray]->wallhity = vrs->rayvars.hwhy;
		vrs->ray[iray]->washitvertical = 0;
	}
}

void	getrightray(t_data *vrs, int iray)
{
	vrs->rayvars.hhd = vrs->rayvars.foundhwh
		? distbtnpts(vrs->player->x,
		vrs->player->y, vrs->rayvars.hwhx, vrs->rayvars.hwhy)
		: INT_MAX;
	vrs->rayvars.vhd = vrs->rayvars.foundvwh
		? distbtnpts(vrs->player->x,
		vrs->player->y, vrs->rayvars.vwhx, vrs->rayvars.vwhy)
		: INT_MAX;
	rightray(vrs, iray);
	vrs->ray[iray]->rayangle = vrs->rayvars.rayangle;
	vrs->ray[iray]->israyfacingdown = vrs->rayvars.isrfd;
	vrs->ray[iray]->israyfacingup = vrs->rayvars.isrfu;
	vrs->ray[iray]->israyfacingleft = vrs->rayvars.isrfl;
	vrs->ray[iray]->israyfacingright = vrs->rayvars.isrfr;
}

void	castray(t_data *vrs, float rayangle, int iray)
{
	horizray(vrs, rayangle, iray);
	vertray(vrs, iray);
	getrightray(vrs, iray);
}

void	castallrays(t_data *vrs)
{
	float rayangle;

	get_player_pos(vrs);
	vrs->ray = malloc(sizeof(t_ray*) * vrs->num_rays);
	rayangle = vrs->player->rotationangle - (FOV_ANGLE / 2);
	vrs->i = -1;
	while (++(vrs->i) < vrs->num_rays)
	{
		vrs->ray[vrs->i] = new_ray();
		vrs->ray[vrs->i]->washitsprit = 0;
		castray(vrs, rayangle, vrs->i);
		rayangle += FOV_ANGLE / vrs->num_rays;
	}
}
