/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:43:34 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 16:24:47 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_north_path(t_filecub *rfilecub, char *line, int *i)
{
	if (!(rfilecub->icub->no))
	{
		if (!(rfilecub->icub->no = ft_substr2(line, *i)))
		{
			rfilecub->error = 6;
			return (0);
		}
		*i += ft_strlen2(rfilecub->icub->no) - 1;
	}
	else
	{
		rfilecub->error = 6;
		return (0);
	}
	return (1);
}

int		get_no(t_filecub *rfilecub, char *line, int i)
{
	if (line[i] != ' ' || rfilecub->icub->no)
	{
		rfilecub->error = 6;
		return (0);
	}
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
			continue;
		else if (!get_north_path(rfilecub, line, &i))
			return (0);
	}
	if (!(rfilecub->icub->no))
	{
		rfilecub->error = 6;
		return (0);
	}
	return (1);
}
