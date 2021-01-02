/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_vrbs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:58:00 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/02 10:43:28 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    inslz_colr_and_map(t_filecub *rcub)
{
    rcub->icub->f->red = -1;
    rcub->icub->f->green = -1;
    rcub->icub->f->blue = -1;
    rcub->icub->c->red = -1;
    rcub->icub->c->green = -1;
    rcub->icub->c->blue = -1;
    rcub->icub->map = NULL;
    rcub->map = NULL;
    rcub->fnshmap = 0;
    rcub->cpt = 0;
    rcub->bigrow = 0;
}


t_filecub *freadfile()
{
    t_filecub *rcub;
    
    rcub = malloc(sizeof(t_filecub));
    rcub->icub = malloc(sizeof(t_infcub));
    rcub->icub->f = malloc(sizeof(t_rgbcolor));
    rcub->icub->c = malloc(sizeof(t_rgbcolor));
    rcub->b = 0;
    rcub->startedmap = 0;
    rcub->find_plr = 0;
    rcub->icub->winwidth = -1;
    rcub->icub->winheight = -1;
    rcub->icub->no = NULL;
    rcub->icub->so = NULL;
    rcub->icub->we = NULL;
    rcub->icub->ea = NULL;
    rcub->icub->s = NULL;
    inslz_colr_and_map(rcub);
    return (rcub);
}


void errorfunc(int ernumber)
{
    printf("error number %d", ernumber);
}