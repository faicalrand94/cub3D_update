/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:00:57 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/02 10:39:23 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_inside_map(t_filecub *rfilecub)
{
    int i;
    int j;   

    i = -1;
    while (++i < rfilecub->cpt)
    {
        j = -1;
        while (++j < rfilecub->bigrow)
        {
            if (rfilecub->icub->map[i][j] == ' '
            || rfilecub->icub->map[i][j] == '1')
                continue ;
            else
                if (!incside_map(rfilecub, i, j))
                {
                    rfilecub->error = 14;
                    return (0);
                }
        }
    }
    return (1);
}

int count_colsrows(t_filecub *rfilecub)
{
    rfilecub->fstads = rfilecub->map;
    while (rfilecub->fstads)
    {
        (rfilecub->cpt)++;
        if((int)ft_strlen2(rfilecub->fstads->maprow) > rfilecub->bigrow)
            rfilecub->bigrow = ft_strlen2(rfilecub->fstads->maprow);
        rfilecub->fstads = rfilecub->fstads->next;
    }
    if (rfilecub->cpt < 3)
    {
        rfilecub->error = 27;
        return (0);
    }
    return (1);
}

void    rmp_list_map(t_filecub *rfilecub)
{
    int i;
    int j;

    i = -1;
    j = -1;
    rfilecub->icub->map = malloc(sizeof(char *) * rfilecub->cpt);
    rfilecub->fstads = rfilecub->map;
    while (++i < rfilecub->cpt)
    {
        rfilecub->icub->map[i] = malloc(sizeof(char) * (rfilecub->bigrow + 1));
        j = -1;
        while (++j < rfilecub->bigrow)
            if (j < (int)ft_strlen2(rfilecub->fstads->maprow))
                rfilecub->icub->map[i][j] = rfilecub->fstads->maprow[j];
            else
                rfilecub->icub->map[i][j] = ' ';
        rfilecub->icub->map[i][j] = '\0';
        rfilecub->fstads = rfilecub->fstads->next;
    }
}

void    freelistmap(t_filecub *rfilecub)
{
    while (rfilecub->map)
    {
        free(rfilecub->map->maprow);
        rfilecub->map->maprow = NULL;
        rfilecub->fstads = rfilecub->map->next;
        free(rfilecub->map);
        rfilecub->map = NULL;
        rfilecub->map = rfilecub->fstads;
    }
}

int creat_map(t_filecub *rfilecub)
{
    if (!count_colsrows(rfilecub))
        return (0);
    rmp_list_map(rfilecub);
    freelistmap(rfilecub);
    if (!trait_map(rfilecub))
        return (0);
    return (1);
}