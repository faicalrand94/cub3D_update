/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:36:40 by fbouibao          #+#    #+#             */
/*   Updated: 2021/01/02 10:33:27 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"

typedef    struct    s_listrows
{
    char            *maprow;
    struct s_listrows    *next;
}                t_listrows;

typedef	struct	s_rgbcolor
{
    int             red;
    int             green;
    int             blue;
}				t_rgbcolor;

typedef	struct	s_infcub
{
    int             winwidth;
    int             winheight;
    char			*no;
    char			*so;
    char			*we;
    char			*ea;
    char            *s;
    t_rgbcolor      *f;
    t_rgbcolor      *c;
    char            **map;
}				t_infcub;

typedef	struct	s_filecub
{
    int             error;
    int             b;
    int             fnshmap;
    int             find_plr;
    int             cpt;
    int             bigrow;
    int             startedmap;
    t_infcub        *icub;
    t_listrows    *map;
    t_listrows    *fstads;
}				t_filecub;

char	*ft_substr_o(char const *s, unsigned int start, int len);
void	ft_lstadd_back2(t_filecub *a, char *str);
char	*ft_substr2(char *s, unsigned int start);
char		*ft_substr3(char *s, unsigned int start);
int		ft_isdigit2(int c);
int		ft_atoi2(const char *c, int i);
int    get_resolution(t_filecub *rfilecub, char *line, int i);
int     get_no(t_filecub *rfilecub, char *line, int i);
int     get_so(t_filecub *rfilecub, char *line, int i);
int     get_we(t_filecub *rfilecub, char *line, int i);
int     get_ea(t_filecub *rfilecub, char *line, int i);
int     get_s(t_filecub *rfilecub, char *line, int i);
int    get_f(t_filecub *rfilecub, char *line, int i);
int    get_c(t_filecub *rfilecub, char *line, int i);
int    ft_sre_v(char *line, int i);
int     check_line_map(t_filecub *rfilecub, char *line);
int creat_map(t_filecub *rfilecub);
int incside_map(t_filecub *rfilecub, int i, int j);
int exist_plr(t_filecub *rfilecub);
int    space_line(char *line);
int     check_idf(t_filecub *rfilecub);
t_filecub *freadfile();
void errorfunc(int ernumber);
char* deletespace(char *str);
int     ft_isnumber(char *str);
int sizeofcolor(t_filecub *rfilecub, int i);
int check_inside_map(t_filecub *rfilecub);
int trait_map(t_filecub *rfilecub);

#endif
