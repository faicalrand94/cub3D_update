/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_readfile2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:09:22 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/29 10:21:10 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     check_idf(t_filecub *rfilecub)
{
    if (rfilecub->icub->winwidth > 0 && rfilecub->icub->winheight > 0 &&
     rfilecub->icub->no && rfilecub->icub->so && 
     rfilecub->icub->we && rfilecub->icub->ea && rfilecub->icub->s && 
     rfilecub->icub->f->red >= 0 && rfilecub->icub->f->green >= 0 && rfilecub->icub->f->blue >= 0 &&
     rfilecub->icub->c->red >= 0 && rfilecub->icub->c->green >= 0 && rfilecub->icub->c->blue >= 0)
    {
        rfilecub->b = 1;
        return (1);
    }
    return (0);
}

int    space_line(char *line)
{
    int i;
    int b;

    i = -1;
    b = 1;
    if (line[0] == '\0')
        return (0);
    while (line[++i] != '\0')
        if (line[i] != ' ')
            return (0);
    return (b);
}

int exist_plr(t_filecub *rfilecub)
{
    int i;
    int j;

    i = -1;
    while (++i < rfilecub->cpt)
    {
        j = -1;
        while (++j < rfilecub->bigrow)
        {
            if (rfilecub->icub->map[i][j] == 'N' || rfilecub->icub->map[i][j] == 'S' ||
             rfilecub->icub->map[i][j] == 'E' || rfilecub->icub->map[i][j] == 'W')
                return (1);
        }
    }
    return (0);
}

int incside_map(t_filecub *rfilecub, int i, int j)
{
    if (rfilecub->icub->map[i - 1][j] == ' ' || rfilecub->icub->map[i + 1][j] == ' ' ||
     rfilecub->icub->map[i][j - 1] == ' ' || rfilecub->icub->map[i][j + 1] == ' ')
        return (0);
    return (1);
}

int    ft_sre_v(char *line, int i)
{
    if (line[i] == ',')
        return (0);
    while (line[i])
    {
        if (line[i] == ',')
            return (i);
        i++;
    }
    return (0);
}