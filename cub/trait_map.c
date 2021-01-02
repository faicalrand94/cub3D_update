/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 10:22:27 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/02 10:31:13 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_first_row(t_filecub *rfilecub)
{
    int j;

    j = -1;
    while (++j < rfilecub->bigrow)
    {
        if (rfilecub->icub->map[0][j] == ' ' || rfilecub->icub->map[0][j] == '1')
            continue ;
        else
        {
            rfilecub->error = 14;
            return (0);
        }
    }
    return (1);
}

int check_last_row(t_filecub *rfilecub)
{
    int j;

    j = -1;
    while (++j < rfilecub->bigrow)
    {
        if (rfilecub->icub->map[rfilecub->cpt - 1][j] == ' ' ||
         rfilecub->icub->map[rfilecub->cpt - 1][j] == '1')
            continue ;
        else
        {
            rfilecub->error = 14;
            return (0);
        }
    }
    return (1);
}

int begin_of_row(t_filecub *rfilecub, int i)
{
    int j;    

    j = -1;
    while (++j < rfilecub->bigrow)
    {
        if (rfilecub->icub->map[i][j] == ' ')
            continue ;
        else if (rfilecub->icub->map[i][j] == '1')
            break ;
        else
        {
            rfilecub->error = 14;
            return (0);
        }
    }
    return (1);
}

int end_of_row(t_filecub *rfilecub, int i)
{
    int j;    

    j = rfilecub->bigrow;
    while (--j >= 0)
    {
        if (rfilecub->icub->map[i][j] == ' ')
            continue ;
        else if (rfilecub->icub->map[i][j] == '1')
            break ;
        else
        {
            rfilecub->error = 14;
            return (0);
        }
    }
    return (1);
}

int trait_map(t_filecub *rfilecub)
{
    int i;

    i = -1;
    if (!check_first_row(rfilecub))
        return (0);
    if (!check_last_row(rfilecub))
        return (0);
    while (++i < rfilecub->cpt)
    {
        if (!begin_of_row(rfilecub, i))
            return (0);
        if (!end_of_row(rfilecub, i))
            return (0);
    }
    if (!check_inside_map(rfilecub))
        return (0);
    if (!exist_plr(rfilecub))
    {
        rfilecub->error = 26;
        return (0);
    }
    return (1);
}