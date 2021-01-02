/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:01:14 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/27 11:52:14 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	freeraysprit(t_data *vrs, int i)
{
	t_sprit	*tmp;
	t_sprit	*tmp2;

	tmp = vrs->ray[i]->sprit;
	while (1)
	{
		if (!tmp->next)
		{
			free(tmp);
			break ;
		}
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void	free_rays(t_data *vrs)
{
	int	i;

	i = -1;
	while (++i < vrs->num_rays)
	{
		if (vrs->ray[i]->washitsprit)
			freeraysprit(vrs, i);
		free(vrs->ray[i]);
	}
	free(vrs->ray);
}

void	freeall(t_filecub *rfcub)
{
	int	i;

	i = -1;
	free(rfcub->icub->no);
	free(rfcub->icub->so);
	free(rfcub->icub->ea);
	free(rfcub->icub->we);
	free(rfcub->icub->s);
	free(rfcub->icub->c);
	free(rfcub->icub->f);
	while (++i < rfcub->cpt)
		free(rfcub->icub->map[i]);
	free(rfcub->icub->map);
	free(rfcub->icub);
	free(rfcub);
}

void	freexit(t_data *vrs)
{
	int	i;

	i = -1;
	while (++i < vrs->cpt)
		free(vrs->maps[i]);
	free(vrs->maps);
	free(vrs->player);
	free(vrs);
}

void	freevrs(t_data *vrs)
{
	free(vrs->player);
	free(vrs);
}
