/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_readfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:32:25 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/02 15:47:02 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr_o(char const *s, unsigned int start, int len)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	if (s)
	{
		p = (char *)malloc(sizeof(char) * len + 1);
		if (!p || start >= ft_strlen2(s))
			return (ft_strdup2("\0"));
		if (s)
		{
			while (s[i] && len > 0)
			{
				p[j] = s[i];
				j++;
				i++;
				len--;
			}
			p[j] = '\0';
			return ((char *)p);
		}
	}
	return (NULL);
}

void	ft_lstadd_back2(t_filecub *a, char *str)
{
	if (!a->map)
	{
		a->map = (t_listrows*)malloc(sizeof(t_listrows));
		a->map->next = NULL;
		a->map->maprow = ft_strdup2(str);
		a->fstads = a->map;
		a->startedmap = 1;
		return ;
	}
	while (a->map)
	{
		if (!a->map->next)
		{
			a->map->next = (t_listrows*)malloc(sizeof(t_listrows));
			a->map->next->next = NULL;
			a->map->next->maprow = ft_strdup2(str);
			a->map = a->fstads;
			a->startedmap = 1;
			return ;
		}
		a->map = a->map->next;
	}
}

char		*ft_substr3(char *s, unsigned int start)
{
	char	*str;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(ft_strlen2(s) - start + 1)))
		return (NULL);
	j = 0;
	while (s[start] != ' ' && s[start] != '\0')
	{
		str[j] = s[start];
		start++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int		ft_isdigit2(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi2(const char *c, int i)
{
	int		signe;
	long	r;

	signe = 1;
	r = 0;
	if (!c)
		return (-3);
	while (c[i] && (c[i] == '\t' || c[i] == '\n' || c[i] == '\r' || c[i] == '\v'
				|| c[i] == '\f' || c[i] == ' '))
		i++;
	if (c[i] == '-')
		signe = -1;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (ft_isdigit2(c[i]))
	{
		r = (r * 10) + (c[i] - '0');
		if ((r * signe) > 2147483647)
			return (-1);
		else if ((r * signe) < -2147483648)
			return (-2);
		i++;
	}
	return ((int)(r * signe));
}
