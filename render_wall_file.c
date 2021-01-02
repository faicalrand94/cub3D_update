/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 09:29:43 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/28 14:27:50 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rnfr_wall(t_data *vrs, int i)
{
	if (!vrs->ray[i]->washitvertical && !vrs->ray[i]->israyfacingdown)
	{
		vrs->util.texelcolor =
			vrs->wallpointerup[(vrs->widthtex * vrs->util.texofsy)
			+ vrs->util.texofsetx];
	}
	else if (vrs->ray[i]->washitvertical && !vrs->ray[i]->israyfacingright)
	{
		vrs->util.texelcolor =
			vrs->wallpointerleft[(vrs->widthtex * vrs->util.texofsy)
			+ vrs->util.texofsetx];
	}
	else if (vrs->ray[i]->washitvertical && !vrs->ray[i]->israyfacingleft)
	{
		vrs->util.texelcolor =
			vrs->wallpointerright[(vrs->widthtex * vrs->util.texofsy)
			+ vrs->util.texofsetx];
	}
	else if (!vrs->ray[i]->washitvertical && !vrs->ray[i]->israyfacingup)
	{
		vrs->util.texelcolor =
			vrs->wallpointerdown[(vrs->widthtex * vrs->util.texofsy)
			+ vrs->util.texofsetx];
	}
	vrs->frame[(vrs->win_width * vrs->util.y) + i] = vrs->util.texelcolor;
}

void	render_wall(t_data *vrs, int i)
{
	util3d(vrs, i);
	if (vrs->ray[i]->washitvertical)
		vrs->util.texofsetx = (int)vrs->ray[i]->wallhity % vrs->heighttex;
	else
		vrs->util.texofsetx = (int)vrs->ray[i]->wallhitx % vrs->widthtex;
	vrs->util.y = vrs->util.wtoppxl - 1;
	while (++(vrs->util.y) < vrs->util.wbopxl)
	{
		vrs->util.distfrmt = vrs->util.y +
			(vrs->util.wllstrphght / 2) - (vrs->win_height / 2);
		vrs->util.texofsy = vrs->util.distfrmt *
			((float)vrs->heighttex / vrs->util.wllstrphght);
		rnfr_wall(vrs, i);
	}
}
