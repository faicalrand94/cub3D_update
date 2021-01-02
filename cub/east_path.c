/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   east_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:50:20 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 16:11:40 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_east_path(t_filecub *rfilecub, char *line, int *i)
{
	if (!(rfilecub->icub->ea))
	{
		if (!(rfilecub->icub->ea = ft_substr2(line, *i)))
		{
			rfilecub->error = 9;
			return (0);
		}
		*i += ft_strlen2(rfilecub->icub->ea) - 1;
	}
	else
	{
		rfilecub->error = 9;
		return (0);
	}
	return (1);
}

int		get_ea(t_filecub *rfilecub, char *line, int i)
{
	if (line[i] != ' ' || rfilecub->icub->ea)
	{
		rfilecub->error = 9;
		return (0);
	}
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
			continue ;
		else if (!get_east_path(rfilecub, line, &i))
			return (0);
	}
	if (!(rfilecub->icub->ea))
	{
		rfilecub->error = 9;
		return (0);
	}
	return (1);
}
