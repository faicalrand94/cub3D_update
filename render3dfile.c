/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3dfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:15:47 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/28 16:20:27 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	util3d(t_data *vrs, int i)
{
	vrs->util.crtdist = vrs->ray[i]->distance *
		cos((vrs->ray[i]->rayangle - vrs->player->rotationangle));
	vrs->util.crtdist = (vrs->util.crtdist == 0)
		? TILE_SIZE + 1
		: vrs->util.crtdist;
	vrs->util.disteprjpln = (vrs->win_width / 2) / tan(FOV_ANGLE / 2);
	vrs->util.pjctedwllhght = (TILE_SIZE / vrs->util.crtdist)
		* vrs->util.disteprjpln;
	vrs->util.wllstrphght = (int)vrs->util.pjctedwllhght;
	vrs->util.wtoppxl = (vrs->win_height / 2) - (vrs->util.wllstrphght / 2);
	vrs->util.wtoppxl = vrs->util.wtoppxl < 0 ? 0 : vrs->util.wtoppxl;
	vrs->util.wbopxl = (vrs->win_height / 2) + (vrs->util.wllstrphght / 2);
	vrs->util.wbopxl = vrs->util.wbopxl > vrs->win_height
		? vrs->win_height
		: vrs->util.wbopxl;
}

void	render_ceil_floor(t_data *vrs, int i)
{
	vrs->util.y = -1;
	while (++(vrs->util.y) < vrs->util.wtoppxl)
		vrs->frame[(vrs->win_width * vrs->util.y) + i] = vrs->ceilcolor;
	vrs->util.y = vrs->util.wbopxl - 1;
	while (++(vrs->util.y) < vrs->win_height)
		vrs->frame[(vrs->win_width * vrs->util.y) + i] = vrs->floorcolor;
}

void	draw_3dproj(t_data *vrs)
{
	int	i;

	vrs->img = mlx_new_image(vrs->mlx, vrs->win_width, vrs->win_height);
	vrs->frame = (int*)mlx_get_data_addr(vrs->img,
			&vrs->useless, &vrs->useless, &vrs->useless);
	i = -1;
	while (++i < vrs->num_rays)
	{
		util3d(vrs, i);
		render_ceil_floor(vrs, i);
		render_wall(vrs, i);
		render_w_s(vrs, i);
	}
}
