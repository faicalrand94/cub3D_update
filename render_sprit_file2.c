/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprit_file2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:42:05 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/28 15:56:00 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		sprit_toos(t_data *vrs, int plus, t_sprit *sprit)
{
	int	texofsetx;
	int	distcp;

	if (plus)
	{
		distcp = (int)distbtnpts(sprit->xsprit,
				sprit->ysprit, sprit->centrex, sprit->centrey);
		distcp = (vrs->widthtexsprit / 2) + distcp;
		texofsetx = distcp * (int)vrs->widthtexsprit / TILE_SIZE;
	}
	else
	{
		distcp = (int)distbtnpts(sprit->xsprit,
				sprit->ysprit, sprit->centrex, sprit->centrey);
		distcp = (vrs->widthtexsprit / 2) - distcp;
		texofsetx = distcp * (int)vrs->widthtexsprit / TILE_SIZE;
	}
	return (texofsetx);
}

int		sprit_rnd(t_data *vrs, int up, t_sprit *sprit)
{
	if (up == 4)
		if (sprit->ysprit > sprit->centrey)
			vrs->util.texofsetx = sprit_toos(vrs, 1, sprit);
		else
			vrs->util.texofsetx = sprit_toos(vrs, 0, sprit);
	else if (up == 3)
		if (sprit->ysprit < sprit->centrey)
			vrs->util.texofsetx = sprit_toos(vrs, 1, sprit);
		else
			vrs->util.texofsetx = sprit_toos(vrs, 0, sprit);
	else if (up == 1)
		if (sprit->xsprit > sprit->centrex)
			vrs->util.texofsetx = sprit_toos(vrs, 1, sprit);
		else
			vrs->util.texofsetx = sprit_toos(vrs, 0, sprit);
	else
	{
		if (sprit->xsprit < sprit->centrex)
			vrs->util.texofsetx = sprit_toos(vrs, 1, sprit);
		else
			vrs->util.texofsetx = sprit_toos(vrs, 0, sprit);
	}
	return (vrs->util.texofsetx);
}

void	spritview(t_data *vrs, int i, t_sprit *sprit)
{
	if (vrs->player->y >= (sprit->centrey - 32)
			&& vrs->player->y <= (sprit->centrey + 32)
			&& vrs->ray[i]->israyfacingright)
		vrs->util.texofsetx = sprit_rnd(vrs, 4, sprit);
	else if (vrs->player->y >= (sprit->centrey - 32)
			&& vrs->player->y <= (sprit->centrey + 32))
		vrs->util.texofsetx = sprit_rnd(vrs, 3, sprit);
	else if (vrs->ray[i]->israyfacingup)
		vrs->util.texofsetx = sprit_rnd(vrs, 1, sprit);
	else if (vrs->ray[i]->israyfacingdown)
		vrs->util.texofsetx = sprit_rnd(vrs, 0, sprit);
}
