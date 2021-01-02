/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   south_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:45:47 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 16:23:10 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_south_path(t_filecub *rfilecub, char *line, int *i)
{
	if (!(rfilecub->icub->so))
	{
		if (!(rfilecub->icub->so = ft_substr2(line, *i)))
		{
			rfilecub->error = 7;
			return (0);
		}
		*i += ft_strlen2(rfilecub->icub->so) - 1;
	}
	else
	{
		rfilecub->error = 7;
		return (0);
	}
	return (1);
}

int		get_so(t_filecub *rfilecub, char *line, int i)
{
	if (line[i] != ' ' || rfilecub->icub->so)
	{
		rfilecub->error = 7;
		return (0);
	}
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
			continue;
		else if (!get_south_path(rfilecub, line, &i))
			return (0);
	}
	if (!(rfilecub->icub->so))
	{
		rfilecub->error = 7;
		return (0);
	}
	return (1);
}
