/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:18:17 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/31 12:08:18 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

















int     ft_strcmp(char *s1, char *s2)
{
    if (ft_strlen2(s1) == ft_strlen2(s2))
    {
        if (s1[0] == s2[0]
        && s1[1] == s2[1] 
        && s1[2] == s2[2])
            return (1);
    }
    return (0);
}


int     finextention(char *filemap, int i)
{
    if (ft_strcmp("cub", filemap + i + 1))
        return(1);
    ft_printf("ERROR : file must .cub extention");
    exit(0);
    return (0);
}

int     vilidetention(char *filemap)
{
    int i;
    int b;

    b = -1;
    i = -1;
    while (filemap[++i])
    {
        if (filemap[i] == '.')
            b = i;
    }
    if (b == -1)
    {
        ft_printf("ERROR : file must .cub extention");
        exit(0);
        return(0);
    }
    if (!finextention(filemap, b))
        return (0);
    if (open(filemap, O_RDONLY) == -1)
    {
        ft_printf("ERROR : file is not exist");
        exit(0);
        return (0);
    }
        
    return (1);
}

int     lastparam(char *str)
{
    if (ft_strlen(str) != 6)
    {
        ft_printf("the second argument must be --save");
        exit (0);
        return (0);
    }
    if (str[0] == '-' && str[1] == '-'
     && str[2] == 's' && str[3] == 'a'
     && str[4] == 'v' && str[5] == 'e')
        return (1);
    ft_printf("the second argument must be --save");
    return (0);
}

int main(int argc, char *argv[])
{
    int b;

    b = 0;
    if (argc == 1)
    {
        ft_printf("you need to specify file with .cub extention");
        system("leaks cub3D");
        return (0);
    }
    else if (argc == 2)
    {
        if (!vilidetention(argv[1]))
        {
            system("leaks cub3D");
            return (0);
        }
    }
    else if (argc == 3)
    {
        if (!vilidetention(argv[1]))
        {
            system("leaks cub3D");
            return (0);
        }
        if (!lastparam(argv[2]))
        {
            system("leaks cub3D");
            return (0);
        }
        b = 1;
    }
    getstart(argv[1], b);
    system("leaks cub3D");
    return (0);
}
