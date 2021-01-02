/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastin_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 11:55:02 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/29 18:07:17 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	normalizeangle(float angle)
{
	angle = fmod(angle, (M_PI * 2));
	if (angle < 0)
		angle = (M_PI * 2) + angle;
	return (angle);
}

int		checkwallray(t_data *vrs, float x, float y)
{
	int	idxx;
	int	idxy;

	idxx = x / TILE_SIZE;
	idxy = y / TILE_SIZE;
	if (idxx < 0 || idxx >= vrs->bigrow || idxy < 0 || idxy >= vrs->cpt)
		return (1);
	return (vrs->maps[idxy][idxx] == '1');
}

int		checkwall(t_data *vrs, float x, float y)
{
	int	idxx;
	int	idxy;
	int	angle;
	int	nx;
	int	ny;

	angle = 0;
	while (angle < 360)
	{
		nx = x + cos(angle * (M_PI / 180)) * 4;
		ny = y + sin(angle * (M_PI / 180)) * 4;
		idxx = nx / TILE_SIZE;
		idxy = ny / TILE_SIZE;
		if (idxx < 0 || idxx >= vrs->bigrow || idxy < 0 || idxy >= vrs->cpt)
			return (1);
		if (vrs->maps[idxy][idxx] == '1')
			return (1);
		angle += 90;
	}
	return (0);
}

int		checksprit(t_data *vrs, float x, float y)
{
	int indx;
	int indxy;

	indx = floor(x / TILE_SIZE);
	indxy = floor(y / TILE_SIZE);
	if (indx < 0 || indx >= vrs->bigrow || indxy < 0 || indxy >= vrs->cpt)
		return (0);
	if (vrs->maps[indxy][indx] == '2')
		return (1);
	return (0);
}
