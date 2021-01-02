/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:40:46 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 17:26:00 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_width_rsl(t_filecub *rfilecub, char *line, int *i)
{
    char *str;
    
    str = ft_substr3(line, *i);
    if (!ft_isnumber(str))
    {
        rfilecub->error = 5;
        return (0);
    }
    if ((rfilecub->icub->winwidth = ft_atoi2(str, 0)) == -1 ||
     rfilecub->icub->winwidth > 2560)
        rfilecub->icub->winwidth = 2560;
    else if ((rfilecub->icub->winwidth <= 0) ||
     (rfilecub->icub->winwidth == -2))
    {    
        rfilecub->error = 5;
        return (0);
    }
    *i += ft_strlen2(str) - 1;
    free(str);
	return (1);
}

int		get_height_rsl(t_filecub *rfilecub, char *line, int *i)
{
    char *str;
    
    str = ft_substr3(line, *i);
    if (!ft_isnumber(str))
    {
        rfilecub->error = 5;
        return (0);
    }
    if ((rfilecub->icub->winheight = ft_atoi2(str, 0)) == -1 ||
     rfilecub->icub->winheight > 1440)
        rfilecub->icub->winheight = 1440;
    else if ((rfilecub->icub->winheight <= 0) ||
     (rfilecub->icub->winheight == -2))
    {    
        rfilecub->error = 5;
        return (0);
    }
    *i += ft_strlen2(str) - 1;
    free(str);   
	return (1);
}

int check_rsl_element(t_filecub *rfilecub, char *line, int *i)
{
    if (rfilecub->icub->winwidth == -1)
    {
        if (!get_width_rsl(rfilecub, line, i))
            return (0);
    }
    else if (rfilecub->icub->winheight == -1)
    {
        if (!get_height_rsl(rfilecub, line, i))
            return (0);
    }
    else
    {
        rfilecub->error = 5;
        return (0);
    }
    return (1);
}

int    get_resolution(t_filecub *rfilecub, char *line, int i)
{
    if (line[i] != ' ' || rfilecub->icub->winwidth > 0 || rfilecub->icub->winheight > 0)
    {    
        rfilecub->error = 5;
        return (0);
    }
    while (line[++i] != '\0')
    {
        if (line[i] == ' ')
            continue;
        else if (!check_rsl_element(rfilecub, line, &i))
            return (0);
    }
    if (rfilecub->icub->winwidth <= 0
    || rfilecub->icub->winheight <= 0)
    {    
        rfilecub->error = 5;
        return (0);
    }
    return (1);
}
