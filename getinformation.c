/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:18:41 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/27 11:55:46 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	copymap(t_data *vrs)
{
	int	i;
	int	j;

	vrs->maps = malloc(sizeof(char*) * vrs->cpt);
	i = -1;
	while (++i < vrs->cpt)
	{
		j = -1;
		vrs->maps[i] = malloc(sizeof(char) * (vrs->bigrow + 1));
		while (++j < vrs->bigrow)
		{
			if (vrs->rfilecub->icub->map[i][j] == ' ')
				vrs->maps[i][j] = '1';
			else
				vrs->maps[i][j] = vrs->rfilecub->icub->map[i][j];
		}
		vrs->maps[i][j] = '\0';
	}
}

int		getinfo(t_data *vrs, char *file)
{
	if (!readfromfile(vrs->rfilecub, file))
		return (0);
	vrs->win_width = vrs->rfilecub->icub->winwidth;
	vrs->win_height = vrs->rfilecub->icub->winheight;
	vrs->cpt = vrs->rfilecub->cpt;
	vrs->bigrow = vrs->rfilecub->bigrow;
	vrs->mapwidth = TILE_SIZE * vrs->cpt;
	vrs->mapheight = TILE_SIZE * vrs->bigrow;
	vrs->num_rays = vrs->win_width;
	vrs->ceilcolor = ((vrs->rfilecub->icub->c->red * (256 * 256))
			+ (vrs->rfilecub->icub->c->green * 256)
			+ vrs->rfilecub->icub->c->blue);
	vrs->floorcolor = ((vrs->rfilecub->icub->f->red * 256 * 256)
			+ (vrs->rfilecub->icub->f->green * 256)
			+ vrs->rfilecub->icub->f->blue);
	copymap(vrs);
	return (1);
}
