/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getplrpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:12:27 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/27 11:59:46 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_dir(t_data *vrs)
{
	if (vrs->maps[vrs->i][vrs->j] == 'N')
		vrs->player->rotationangle = 3 * M_PI / 2;
	else if (vrs->maps[vrs->i][vrs->j] == 'S')
		vrs->player->rotationangle = M_PI / 2;
	else if (vrs->maps[vrs->i][vrs->j] == 'E')
		vrs->player->rotationangle = 0;
	else if (vrs->maps[vrs->i][vrs->j] == 'W')
		vrs->player->rotationangle = M_PI;
	vrs->player->x = vrs->posjbric + (TILE_SIZE / 2);
	vrs->player->y = vrs->posibric + (TILE_SIZE / 2);
	vrs->maps[vrs->i][vrs->j] = '0';
}

void	get_player_pos(t_data *vrs)
{
	vrs->i = -1;
	vrs->posibric = 0;
	vrs->posjbric = 0;
	while (++(vrs->i) < vrs->cpt)
	{
		vrs->j = -1;
		while (++(vrs->j) < vrs->bigrow)
		{
			if (vrs->maps[vrs->i][vrs->j] == 'N'
				|| vrs->maps[vrs->i][vrs->j] == 'S'
				|| vrs->maps[vrs->i][vrs->j] == 'E'
				|| vrs->maps[vrs->i][vrs->j] == 'W')
				get_dir(vrs);
			vrs->posjbric += TILE_SIZE;
		}
		vrs->posjbric = 0;
		vrs->posibric += TILE_SIZE;
	}
}
