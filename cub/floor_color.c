/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:52:53 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 16:02:45 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		getred_f(t_filecub *rfilecub, char *line, int *i)
{
	char	*str;
	int		posv;

	str = NULL;
	if (!(posv = ft_sre_v(line, *i))
			|| !(str = ft_substr_o(line, *i, posv - *i))
			|| !ft_isnumber(str)
			|| (rfilecub->icub->f->red = ft_atoi2(str, 0)) < 0)
	{
		if (str)
			free(str);
		rfilecub->error = 11;
		return (0);
	}
	*i = posv;
	free(str);
	return (1);
}

int		getgreen_f(t_filecub *rfilecub, char *line, int *i)
{
	char	*str;
	int		posv;

	str = NULL;
	if (!(posv = ft_sre_v(line, *i))
			|| !(str = ft_substr_o(line, *i, posv - *i))
			|| !ft_isnumber(str)
			|| (rfilecub->icub->f->green = ft_atoi2(str, 0)) < 0)
	{
		if (str)
			free(str);
		rfilecub->error = 11;
		return (0);
	}
	*i = posv;
	free(str);
	return (1);
}

int		getblue_f(t_filecub *rfilecub, char *line, int *i)
{
	char	*str;
	char	*tmp;

	str = NULL;
	str = ft_substr3(line, *i);
	tmp = str;
	str = deletespace(tmp);
	free(tmp);
	if (!str || !ft_isnumber(str)
			|| (rfilecub->icub->f->blue = ft_atoi2(str, 0)) < 0)
	{
		if (str)
			free(str);
		rfilecub->error = 11;
		return (0);
	}
	*i += ft_strlen2(str) - 1;
	free(str);
	return (1);
}

int		check_color_f(t_filecub *rfilecub, char *line, int *i)
{
	if (rfilecub->icub->f->red < 0)
	{
		if (!getred_f(rfilecub, line, i))
			return (0);
	}
	else if (rfilecub->icub->f->green < 0)
	{
		if (!getgreen_f(rfilecub, line, i))
			return (0);
	}
	else if (rfilecub->icub->f->blue < 0)
	{
		if (!getblue_f(rfilecub, line, i))
			return (0);
	}
	else
	{
		rfilecub->error = 11;
		return (0);
	}
	return (1);
}

int		get_f(t_filecub *rfilecub, char *line, int i)
{
	if (line[i] != ' ' || rfilecub->icub->f->blue >= 0 ||
			rfilecub->icub->f->red >= 0 || rfilecub->icub->f->green >= 0)
	{
		rfilecub->error = 11;
		return (0);
	}
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
			continue;
		else
		{
			if (!check_color_f(rfilecub, line, &i))
				return (0);
		}
	}
	if (!sizeofcolor(rfilecub, 1))
		return (0);
	if (rfilecub->icub->f->red < 0 || rfilecub->icub->f->green < 0
		|| rfilecub->icub->f->blue < 0)
	{
		rfilecub->error = 11;
		return (0);
	}
	return (1);
}
