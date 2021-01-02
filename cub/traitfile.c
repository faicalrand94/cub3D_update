// make -C ..  Compile cup3d   ||  ./mlx-test

#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"









int     traiterline(t_filecub *rfilecub, char *line)
{
    int i;

    i = -1;
    while (line[++i] != '\0')
    {
        if (line[i] == 'R')
            return (get_resolution(rfilecub, line, i + 1));
        if (line[i] == 'N' && line[i + 1] == 'O')
            return (get_no(rfilecub, line, i + 2));
        if (line[i] == 'S' && line[i + 1] == 'O')
            return (get_so(rfilecub, line, i + 2));
        if (line[i] == 'W' && line[i + 1] == 'E')
            return (get_we(rfilecub, line, i + 2));
        if (line[i] == 'E' && line[i + 1] == 'A')
            return (get_ea(rfilecub, line, i + 2));
        if (line[i] == 'S')
            return (get_s(rfilecub, line, i + 1));
        if (line[i] == 'F')
            return (get_f(rfilecub, line, i + 1));
        if (line[i] == 'C')
            return (get_c(rfilecub, line, i + 1));
        
        if (check_idf(rfilecub))
            return (1);
        if (line[i] == ' ')
            continue ;
        rfilecub->error = 18;
        return (0);
    }
    if (ft_strlen2(line) > 0 && !rfilecub->b)
    {

        rfilecub->error = 60;
        return (0);
    }
    return (1);
}

int readfromfile(t_filecub   *rfilecub, char *file)
{
    
    char        *line;
    int         rd;
    int         fd;

    fd = open(file, O_RDONLY);
    rfilecub->b = 0;
    while ((rd = get_next_line(fd, &line)) >= 0)
    {
        if (line[0] != '\0')
            if (!rfilecub->b && !traiterline(rfilecub, line))
            {
                errorfunc(rfilecub->error);
                free(line);
                return (0);
            }
        if (rfilecub->b)
        {
            if (!(check_line_map(rfilecub, line)))
            {
                while (rfilecub->map)
                {
                    free(rfilecub->map->maprow);
                    rfilecub->map->maprow = NULL;
                    rfilecub->fstads = rfilecub->map->next;
                    free(rfilecub->map);
                    rfilecub->map = NULL;
                    rfilecub->map = rfilecub->fstads;
                }
                errorfunc(rfilecub->error);
                free(line);
                return (0);
            }
        if (!rfilecub->fnshmap)
            ft_lstadd_back2(rfilecub, line);
        }
        if (!rd && !check_idf(rfilecub))
        {
            errorfunc(18);
            free(line);
            return (0);
        }
        free(line);
        if (!rd)
            break ;    
    }
    if (!creat_map(rfilecub))
    {
        errorfunc(rfilecub->error);
        return (0);
    }
    close(fd);
    return (1);
}



// int main()
// {
//     t_filecub *rfcub;
//     rfcub = freadfile();
//     if (readfromfile(rfcub, "../map.cub"))
//     {
//     int i,j;

//     i = -1;
//     printf("| %d | %d\n", rfcub->cpt, rfcub->bigrow);
//     while (++i < rfcub->cpt)
//     {
//         j = -1;
//         while (++j < rfcub->bigrow)
//         {
//             printf("|%c|", rfcub->icub->map[i][j]);
//         }
//         printf("\n");
//     }
//     }
//     //freeall(rfcub);
//     return 0;
// }
