/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:51:43 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 16:25:24 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_sprit_path(t_filecub *rfilecub, char *line, int *i)
{
	if (!(rfilecub->icub->s))
	{
		if (!(rfilecub->icub->s = ft_substr2(line, *i)))
		{
			rfilecub->error = 9;
			return (0);
		}
		*i += ft_strlen2(rfilecub->icub->s) - 1;
	}
	else
	{
		rfilecub->error = 9;
		return (0);
	}
	return (1);
}

int		get_s(t_filecub *rfilecub, char *line, int i)
{
	if (line[i] != ' ' || rfilecub->icub->s)
	{
		rfilecub->error = 10;
		return (0);
	}
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
			continue;
		else if (!get_sprit_path(rfilecub, line, &i))
			return (0);
	}
	if (!(rfilecub->icub->s))
	{
		rfilecub->error = 10;
		return (0);
	}
	return (1);
}
