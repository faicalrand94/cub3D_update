/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:56:50 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/02 12:58:31 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int chequewallsspace(char *line, int i)
{
    int j;

    j = i + 1;
    while (--j >= 0)
        if (line[j] == '1')
            j = -2;
        else if (line[j] == ' ')
            continue ;
        else
            return (0);
    i--;
    while (line[++i])
        if (line[i] != ' ' && line[i] != '1')
            return (0);
        else if (line[i] == ' ')
            continue ;
        else
            break ;
    if (j == -3)
        return (1);
    return (0);
}

int     check_line_chr(t_filecub *rfilecub, char *line)
{
    int i;
    int b;

    i = -1;
    b = 0;
    while (line[++i])
    {
        if (line[i] == ' ' && !b)
            continue ;
        else if (line[i] == ' ' && chequewallsspace(line, i))
            continue ;
        else if (line[i] == '1' || line[i] == '0' || line[i] == '2')
            b = 1;
        else if (!rfilecub->find_plr && (line[i] == 'N' || line[i] == 'S'
         || line[i] == 'E' || line[i] == 'W'))
            rfilecub->find_plr = 1;
        else
        {
            rfilecub->error = 14;
            return (0);
        }
    }
    if (!b)
        rfilecub->fnshmap = 1;
    return (1);
}

int     check_line_map(t_filecub *rfilecub, char *line)
{
    if (rfilecub->startedmap && line[0] == '\0')
    {
        rfilecub->error = 14;
        return (0);
    }
    else if (space_line(line))
    {
        rfilecub->startedmap = 1;
        return (1);
    }
    else if (!check_line_chr(rfilecub, line))
        return (0);
    return (1);
}