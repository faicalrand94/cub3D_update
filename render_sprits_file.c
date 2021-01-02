/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprits_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 09:35:03 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/28 16:20:41 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	util3dsprit(t_data *vrs, int i, t_sprit *sprit)
{
	vrs->util.crtdist = sprit->centredist *
		cos((vrs->ray[i]->rayangle - vrs->player->rotationangle));
	vrs->util.crtdist = (vrs->util.crtdist == 0)
		? TILE_SIZE + 1 : vrs->util.crtdist;
	vrs->util.disteprjpln = (vrs->win_width / 2) / tan(FOV_ANGLE / 2);
	vrs->util.pjctedwllhght =
		(TILE_SIZE / vrs->util.crtdist) * vrs->util.disteprjpln;
	vrs->util.wllstrphght = (int)vrs->util.pjctedwllhght;
	vrs->util.wtoppxl = (vrs->win_height / 2) - (vrs->util.wllstrphght / 2);
	vrs->util.wtoppxl = vrs->util.wtoppxl < 0 ? 0 : vrs->util.wtoppxl;
	vrs->util.wbopxl = (vrs->win_height / 2) + (vrs->util.wllstrphght / 2);
	vrs->util.wbopxl = vrs->util.wbopxl > vrs->win_height
		? vrs->win_height : vrs->util.wbopxl;
}

void	render_sprit_cnt(t_data *vrs, int i)
{
	vrs->util.y = vrs->util.wtoppxl - 1;
	if (vrs->util.texofsetx >= 0 && vrs->util.texofsetx < TILE_SIZE)
		while (++(vrs->util.y) < vrs->util.wbopxl)
		{
			vrs->util.distfrmt = vrs->util.y +
				(vrs->util.wllstrphght / 2) - (vrs->win_height / 2);
			vrs->util.texofsy = vrs->util.distfrmt *
				((float)vrs->heighttexsprit / vrs->util.wllstrphght);
			vrs->util.texelcolor =
				vrs->pointersprit[(vrs->heighttexsprit * vrs->util.texofsy)
				+ vrs->util.texofsetx];
			if (vrs->util.texelcolor != 0)
			{
				vrs->frame[(vrs->win_width * vrs->util.y) + i] =
					vrs->util.texelcolor;
			}
		}
}

void	render_sprit(t_data *vrs, int i, t_sprit *sprit)
{
	util3dsprit(vrs, i, sprit);
	spritview(vrs, i, sprit);
	render_sprit_cnt(vrs, i);
}

void	render_w_s(t_data *vrs, int i)
{
	t_sprit *sprit;
	t_sprit *tmp;

	if (vrs->ray[i]->washitsprit)
	{
		sprit = vrs->ray[i]->sprit;
		while (1)
		{
			if (vrs->ray[i]->distance > sprit->distance)
				render_sprit(vrs, i, sprit);
			if (!sprit->next)
				return ;
			tmp = sprit;
			sprit = sprit->next;
		}
		free(tmp);
	}
}
