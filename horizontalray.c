/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontalray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 11:33:52 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/29 17:30:36 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		checkwallsprit(t_data *vrs, int iray)
{
	if (checksprit(vrs, vrs->rayvars.xtocheck, vrs->rayvars.ytocheck))
	{
		vrs->rayvars.shx = vrs->rayvars.nhtx;
		vrs->rayvars.shy = vrs->rayvars.nhty;
		vrs->ray[iray]->washitsprit = 1;
		vrs->rayvars.foundvsh = 0;
		prpsprit(vrs, vrs->rayvars, iray);
	}
	if (checkwallray(vrs, vrs->rayvars.xtocheck, vrs->rayvars.ytocheck))
	{
		vrs->rayvars.hwhx = vrs->rayvars.nhtx;
		vrs->rayvars.hwhy = vrs->rayvars.nhty;
		vrs->rayvars.foundhwh = 1;
		return (0);
	}
	else
	{
		vrs->rayvars.nhtx += vrs->rayvars.xstep;
		vrs->rayvars.nhty += vrs->rayvars.ystep;
	}
	return (1);
}

void	normeinirayhrz(t_data *vrs, int iray)
{
	vrs->rayvars.xintercept = vrs->player->x +
	(vrs->rayvars.yintercept - vrs->player->y) / tan(vrs->rayvars.rayangle);
	vrs->rayvars.ystep = TILE_SIZE;
	vrs->rayvars.ystep *= vrs->rayvars.isrfu ? -1 : 1;
	vrs->rayvars.xstep = TILE_SIZE / tan(vrs->rayvars.rayangle);
	vrs->rayvars.xstep *= (vrs->rayvars.isrfl
	&& vrs->rayvars.xstep > 0) ? -1 : 1;
	vrs->rayvars.xstep *= (vrs->rayvars.isrfr
	&& vrs->rayvars.xstep < 0) ? -1 : 1;
	vrs->rayvars.nhtx = vrs->rayvars.xintercept;
	vrs->rayvars.nhty = vrs->rayvars.yintercept;
	vrs->ray[iray]->sprit = NULL;
}

void	inicialrayhorz(t_data *vrs, float rayangle, int iray)
{
	vrs->rayvars.rayangle = normalizeangle(rayangle);
	vrs->ray[iray]->rayangle = vrs->rayvars.rayangle;
	vrs->ray[iray]->washitsprit = 0;
	vrs->rayvars.isrfd = vrs->rayvars.rayangle > 0
	&& vrs->rayvars.rayangle < PI;
	vrs->rayvars.isrfu = !vrs->rayvars.isrfd;
	vrs->rayvars.isrfr = vrs->rayvars.rayangle < 0.5 * PI
	|| vrs->rayvars.rayangle > 1.5 * PI;
	vrs->rayvars.isrfl = !vrs->rayvars.isrfr;
	vrs->rayvars.foundhwh = 0;
	vrs->rayvars.hwhx = 0;
	vrs->rayvars.hwhy = 0;
	vrs->rayvars.shx = 0;
	vrs->rayvars.shy = 0;
	vrs->rayvars.yintercept = floor(vrs->player->y / TILE_SIZE) * TILE_SIZE;
	vrs->rayvars.yintercept += vrs->rayvars.isrfd ? TILE_SIZE : 0;
	normeinirayhrz(vrs, iray);
}

void	horizray(t_data *vrs, float rayangle, int iray)
{
	inicialrayhorz(vrs, rayangle, iray);
	while (1)
	{
		vrs->rayvars.xtocheck = vrs->rayvars.nhtx;
		vrs->rayvars.ytocheck = vrs->rayvars.nhty +
			(vrs->rayvars.isrfu ? -1 : 0);
		if (!checkwallsprit(vrs, iray))
			break ;
	}
}
