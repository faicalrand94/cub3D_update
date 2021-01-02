/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_readfile3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 15:53:03 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/02 15:47:21 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int sizeofcolor(t_filecub *rfilecub, int i)
{
	if (i == 1)
	{
		if ((rfilecub->icub->f->red >= 0 && rfilecub->icub->f->red <= 255)
			&& (rfilecub->icub->f->green >= 0 && rfilecub->icub->f->green <= 255)
			&& (rfilecub->icub->f->blue >= 0 && rfilecub->icub->f->blue <= 255))
			return (1);
	}
	else if (i == 2)
	{
		if ((rfilecub->icub->c->red >= 0 && rfilecub->icub->c->red <= 255)
			&& (rfilecub->icub->c->green >= 0 && rfilecub->icub->c->green <= 255)
			&& (rfilecub->icub->c->blue >= 0 && rfilecub->icub->c->blue <= 255))
			return (1);
	}
	rfilecub->error = 11;
	return (0);
}

int     ft_isnumber(char *str)
{
    int i;

    i = -1;
    if (str[0] == '+' && (str[1] >= '0' && str[1] <= '9'))
        i++;
    while (str[++i])
    {
        if ((str[i] >= '0' && str[i] <= '9'))
            continue ;
        else
            return (0);        
    }
    return (1);
}

char *get_right_path(char *str, int start, int end)
{
	int i;
	int j;
	char *path;
	
	if (!(path = malloc((sizeof(char) * (end - start)) + 2)))
		return (NULL);
	i = start - 1;
	j = 0;
	while (++i <= end)
	{
		path[j] = str[i];
		j++;
	}
	path[j] = '\0';
	return (path);
}

char* deletespace(char *str)
{
	int size;
	int i;
	int start;
	int end;
	
	start = -1;
	end = -1;
	i = -1;
	size = ft_strlen2(str);
	while (++i < size)
		if (str[i] != ' ')
		{
			start = i;
			break ;
		}
	i = size;
	while (--i >= 0)
		if (str[i] != ' ')
		{
			end = i;
			break ;
		}
	if (start == -1 || end == -1)
		return (NULL);
	return (get_right_path(str, start, end));
}

char	*ft_substr2(char *s, unsigned int start)
{
	char *path;

	if (!s)
		return (NULL);
	if (!(path = deletespace(s + start)))
		return (NULL);
	int gh = open(path, O_RDONLY);
	if (gh == -1)
		return (NULL);
	return (path);
}
