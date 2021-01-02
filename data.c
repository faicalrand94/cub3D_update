/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:55:02 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/27 11:45:36 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_sprit		*new_sprit(void)
{
	t_sprit *sprit;

	sprit = malloc(sizeof(t_sprit));
	sprit->next = NULL;
	return (sprit);
}

t_ray		*new_ray(void)
{
	t_ray *ray;

	ray = malloc(sizeof(t_ray));
	return (ray);
}

t_player	*setup(void)
{
	t_player	*plr;

	plr = malloc(sizeof(t_player));
	plr->turndirection = 0;
	plr->walkdirection = 0;
	plr->walkspeed = 19;
	plr->turnspeed = 10 * (PI / 180);
	return (plr);
}

t_data		*nvrbs(void)
{
	t_data *vrs;

	vrs = malloc(sizeof(t_data));
	vrs->posibric = 0;
	vrs->posjbric = 0;
	vrs->player = setup();
	vrs->player->walkdirection = 0;
	vrs->player->turndirection = 0;
	vrs->player->walkleft = 0;
	vrs->player->walkright = 0;
	return (vrs);
}
