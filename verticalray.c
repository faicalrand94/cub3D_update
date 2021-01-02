/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verticalray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 11:40:27 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/29 17:30:46 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	inicialrayvert(t_data *vrs)
{
	vrs->rayvars.foundvwh = 0;
	vrs->rayvars.foundvsh = 0;
	vrs->rayvars.vwhx = 0;
	vrs->rayvars.vwhy = 0;
	vrs->rayvars.xintercept = floor(vrs->player->x / TILE_SIZE) * TILE_SIZE;
	vrs->rayvars.xintercept += vrs->rayvars.isrfr ? TILE_SIZE : 0;
	vrs->rayvars.yintercept = vrs->player->y +
		(vrs->rayvars.xintercept - vrs->player->x) * tan(vrs->rayvars.rayangle);
	vrs->rayvars.xstep = TILE_SIZE;
	vrs->rayvars.xstep *= vrs->rayvars.isrfl ? -1 : 1;
	vrs->rayvars.ystep = TILE_SIZE * tan(vrs->rayvars.rayangle);
	vrs->rayvars.ystep *= (vrs->rayvars.isrfu && vrs->rayvars.ystep > 0)
		? -1 : 1;
	vrs->rayvars.ystep *= (vrs->rayvars.isrfd && vrs->rayvars.ystep < 0)
		? -1 : 1;
	vrs->rayvars.nvtx = vrs->rayvars.xintercept;
	vrs->rayvars.nvty = vrs->rayvars.yintercept;
	vrs->rayvars.shx = 0;
	vrs->rayvars.shy = 0;
}

void	notsprit(t_data *vrs, int iray)
{
	vrs->rayvars.shx = vrs->rayvars.nvtx;
	vrs->rayvars.shy = vrs->rayvars.nvty;
	vrs->rayvars.foundvsh = 1;
	vrs->ray[iray]->washitsprit = 1;
	prpsprit(vrs, vrs->rayvars, iray);
}

void	vertray(t_data *vrs, int iray)
{
	inicialrayvert(vrs);
	while (1)
	{
		vrs->rayvars.xtocheck = vrs->rayvars.nvtx +
			(vrs->rayvars.isrfl ? -1 : 0);
		vrs->rayvars.ytocheck = vrs->rayvars.nvty;
		if (checksprit(vrs, vrs->rayvars.xtocheck, vrs->rayvars.ytocheck))
			notsprit(vrs, iray);
		if (checkwallray(vrs, vrs->rayvars.xtocheck, vrs->rayvars.ytocheck))
		{
			vrs->rayvars.vwhx = vrs->rayvars.nvtx;
			vrs->rayvars.vwhy = vrs->rayvars.nvty;
			vrs->rayvars.foundvwh = 1;
			break ;
		}
		else
		{
			vrs->rayvars.nvtx += vrs->rayvars.xstep;
			vrs->rayvars.nvty += vrs->rayvars.ystep;
		}
	}
}
