/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:48:14 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 16:18:30 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_west_path(t_filecub *rfilecub, char *line, int *i)
{
	if (!(rfilecub->icub->we))
	{
		if (!(rfilecub->icub->we = ft_substr2(line, *i)))
		{
			rfilecub->error = 9;
			return (0);
		}
		*i += ft_strlen2(rfilecub->icub->we) - 1;
	}
	else
	{
		rfilecub->error = 9;
		return (0);
	}
	return (1);
}

int		get_we(t_filecub *rfilecub, char *line, int i)
{
	if (line[i] != ' ' || rfilecub->icub->we)
	{
		rfilecub->error = 8;
		return (0);
	}
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
			continue;
		else if (!get_west_path(rfilecub, line, &i))
			return (0);
	}
	if (!(rfilecub->icub->we))
	{
		rfilecub->error = 8;
		return (0);
	}
	return (1);
}
