/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:01:04 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/29 18:06:39 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mdf_dist(t_data *vrs, t_rayvars rayvars, int iray, t_sprit *tmp)
{
	int indx;
	int indxy;

	indx = floor(rayvars.xtocheck / TILE_SIZE);
	indxy = floor(rayvars.ytocheck / TILE_SIZE);
	tmp->centrex = ((indx) * TILE_SIZE) + (TILE_SIZE / 2);
	tmp->centrey = ((indxy) * TILE_SIZE) + (TILE_SIZE / 2);
	tmp->i = indxy;
	tmp->j = indx;
	tmp->id = iray;
	tmp->wasvert = rayvars.foundvsh;
	tmp->xshit = rayvars.shx;
	tmp->yshit = rayvars.shy;
	tmp->distance = distbtnpts(vrs->player->x,
			vrs->player->y, rayvars.shx, rayvars.shy);
	tmp->centredist = distbtnpts(vrs->player->x,
			vrs->player->y, tmp->centrex, tmp->centrey);
	tmp->xsprit = vrs->player->x +
		(tmp->centredist * cos(vrs->ray[iray]->rayangle));
	tmp->ysprit = vrs->player->y +
		(tmp->centredist * sin(vrs->ray[iray]->rayangle));
}

int		firstsprit(t_data *vrs, t_rayvars rayvars, int iray)
{
	int	indx;
	int	indxy;

	indx = floor(rayvars.xtocheck / TILE_SIZE);
	indxy = floor(rayvars.ytocheck / TILE_SIZE);
	if (indx < 0 || indx >= vrs->bigrow || indxy < 0 || indxy >= vrs->cpt)
		return (1);
	if (!vrs->ray[iray]->sprit)
	{
		vrs->ray[iray]->sprit = new_sprit();
		mdf_dist(vrs, rayvars, iray, vrs->ray[iray]->sprit);
		return (1);
	}
	return (0);
}

int		modif_the_sprit(t_data *vrs, t_rayvars rayvars, int iray, float dist)
{
	int		indx;
	int		indxy;
	t_sprit	*tmp;

	indx = floor(rayvars.xtocheck / TILE_SIZE);
	indxy = floor(rayvars.ytocheck / TILE_SIZE);
	tmp = vrs->ray[iray]->sprit;
	while (1)
	{
		if (tmp->i == indxy && tmp->j == indx)
		{
			if (dist <= tmp->distance)
				mdf_dist(vrs, rayvars, iray, tmp);
			return (1);
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (0);
}

int		putrightpos(t_data *vrs, t_rayvars rayvars, int iray, float dist)
{
	rayvars.tmp = vrs->ray[iray]->sprit;
	if (dist >= rayvars.tmp->distance)
	{
		rayvars.tmp2 = new_sprit();
		mdf_dist(vrs, rayvars, iray, rayvars.tmp2);
		rayvars.tmp2->next = rayvars.tmp;
		vrs->ray[iray]->sprit = rayvars.tmp2;
		return (1);
	}
	while (rayvars.tmp->next)
	{
		if (dist >= rayvars.tmp->next->distance)
		{
			rayvars.tmp2 = new_sprit();
			mdf_dist(vrs, rayvars, iray, rayvars.tmp2);
			rayvars.tmp2->next = rayvars.tmp->next;
			rayvars.tmp->next = rayvars.tmp2;
			return (1);
		}
		rayvars.tmp = rayvars.tmp->next;
	}
	rayvars.tmp->next = new_sprit();
	mdf_dist(vrs, rayvars, iray, rayvars.tmp->next);
	return (0);
}

void	prpsprit(t_data *vrs, t_rayvars rayvars, int iray)
{
	float	dist;

	if (firstsprit(vrs, vrs->rayvars, iray))
		return ;
	dist = distbtnpts(vrs->player->x, vrs->player->y, rayvars.shx, rayvars.shy);
	if (modif_the_sprit(vrs, rayvars, iray, dist))
		return ;
	if (putrightpos(vrs, rayvars, iray, dist))
		return ;
}
