/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:54:02 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/01 16:05:22 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		getred(t_filecub *rfilecub, char *line, int *i)
{
	char	*str;
	int		posv;

	str = NULL;
	if (!(posv = ft_sre_v(line, *i))
			|| !(str = ft_substr_o(line, *i, posv - *i))
			|| !ft_isnumber(str)
			|| (rfilecub->icub->c->red = ft_atoi2(str, 0)) < 0)
	{
		if (str)
			free(str);
		rfilecub->error = 12;
		return (0);
	}
	*i = posv;
	free(str);
	return (1);
}

int		getgreen(t_filecub *rfilecub, char *line, int *i)
{
	char	*str;
	int		posv;

	str = NULL;
	if (!(posv = ft_sre_v(line, *i))
			|| !(str = ft_substr_o(line, *i, posv - *i))
			|| !ft_isnumber(str)
			|| (rfilecub->icub->c->green = ft_atoi2(str, 0)) < 0)
	{
		if (str)
			free(str);
		rfilecub->error = 12;
		return (0);
	}
	*i = posv;
	free(str);
	return (1);
}

int		getblue(t_filecub *rfilecub, char *line, int *i)
{
	char	*str;
	char	*tmp;

	str = NULL;
	str = ft_substr3(line, *i);
	tmp = str;
	str = deletespace(tmp);
	free(tmp);
	if (!str || !ft_isnumber(str)
			|| (rfilecub->icub->c->blue = ft_atoi2(str, 0)) < 0)
	{
		if (str)
			free(str);
		rfilecub->error = 12;
		return (0);
	}
	*i += ft_strlen2(str) - 1;
	free(str);
	return (1);
}

int		check_color(t_filecub *rfilecub, char *line, int *i)
{
	if (rfilecub->icub->c->red < 0)
	{
		if (!getred(rfilecub, line, i))
			return (0);
	}
	else if (rfilecub->icub->c->green < 0)
	{
		if (!getgreen(rfilecub, line, i))
			return (0);
	}
	else if (rfilecub->icub->c->blue < 0)
	{
		if (!getblue(rfilecub, line, i))
			return (0);
	}
	else
	{
		rfilecub->error = 12;
		return (0);
	}
	return (1);
}

int		get_c(t_filecub *rfilecub, char *line, int i)
{
	if (line[i] != ' '
			|| rfilecub->icub->c->blue >= 0 ||
			rfilecub->icub->c->red >= 0 || rfilecub->icub->c->green >= 0)
	{
		rfilecub->error = 12;
		return (0);
	}
	while (line[++i] != '\0')
	{
		if (line[i] == ' ')
			continue;
		else if (!check_color(rfilecub, line, &i))
			return (0);
	}
	if (!sizeofcolor(rfilecub, 2))
		return (0);
	if (rfilecub->icub->c->red < 0
			|| rfilecub->icub->c->green < 0
			|| rfilecub->icub->c->blue < 0)
	{
		rfilecub->error = 12;
		return (0);
	}
	return (1);
}
