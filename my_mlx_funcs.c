/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 09:51:35 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/30 16:08:42 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    draw_line(t_data *vrs, int x0, int y0, int x1, int y1)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2;
  while (1){
    vrs->frame[(y0 * vrs->win_width) + x0] = 0xffffff;
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; }
    if (e2 <= dx) { err += dx; y0 += sy; }
  }
}

void draw_map(t_data *vrs) {
    int tilecolor;
    vrs->posibric = 0;
    vrs->posjbric = 0;
    for (int i = 0; i < vrs->cpt; i++) {
        for (int j = 0; j < vrs->bigrow; j++) {
            if (vrs->maps[i][j] != '1')
                tilecolor = 0xFFFFFF00;
            else
                tilecolor = 0x98FB98;           
                

            for (int y = vrs->posibric * 0.2; y < (vrs->posibric + TILE_SIZE) * 0.2; y++)
            {
                for (int x = vrs->posjbric * 0.2; x < (vrs->posjbric + TILE_SIZE) * 0.2; x++)
                {
                    vrs->frame[(y * vrs->win_width) + x] = tilecolor;  
                }
            }
            // if (vrs->maps[i][j] == '2')
            //     for (int y = (vrs->posibric + (TILE_SIZE / 4)) * 0.2; y < ((vrs->posibric + (3 * TILE_SIZE / 4)) * 0.2); y++)
            //     {
            //         for (int x = (vrs->posjbric + (TILE_SIZE / 4)) * 0.2; x < (vrs->posjbric + (3 * TILE_SIZE / 4)) * 0.2; x++)
            //         {
            //             vrs->frame[(y * (TILE_SIZE * 20)) + x] = 0x815a37;  
            //         }
            //     }
            vrs->posjbric += TILE_SIZE;
        }
        vrs->posjbric = 0;
        vrs->posibric += TILE_SIZE;
    }
    //draw_player(vrs);
}

void draw_rays(t_data *vrs) {
    for (int i = 0; i < vrs->num_rays; i++) {
       draw_line(vrs, (vrs->player->x * 0.2), (vrs->player->y * 0.2), (vrs->ray[i]->wallhitx * 0.2), (vrs->ray[i]->wallhity * 0.2));
       // free(vrs->ray[i]);
    }
    //free(vrs->ray);
}

void	call_functions(t_data *vrs)
{
	updateplayerpos(vrs);
	castallrays(vrs);
	draw_3dproj(vrs);
	draw_map(vrs);
	draw_rays(vrs);
	free_rays(vrs);
	mlx_put_image_to_window(vrs->mlx, vrs->mlx_win, vrs->img, 0, 0);
}

int		startandgetex(t_data *vrs)
{
	vrs->mlx = mlx_init();
	vrs->mlx_win = mlx_new_window(vrs->mlx,
	vrs->rfilecub->icub->winwidth, vrs->win_height, "cub3D");
	vrs->walltextureright = mlx_xpm_file_to_image(vrs->mlx,
	vrs->rfilecub->icub->we, &vrs->widthtex, &vrs->heighttex);
	if (!vrs->walltextureright)
	{
		printf("invalid file XPM");
		return (0);
	}
	vrs->wallpointerright = (int*)mlx_get_data_addr(vrs->walltextureright,
	&vrs->useless, &vrs->useless, &vrs->useless);
	vrs->walltextureleft = mlx_xpm_file_to_image(vrs->mlx,
	vrs->rfilecub->icub->ea, &vrs->widthtex, &vrs->heighttex);
	if (!vrs->walltextureleft)
	{
		printf("invalid file XPM");
		return (0);
	}
	vrs->wallpointerleft = (int*)mlx_get_data_addr(vrs->walltextureleft,
	&vrs->useless, &vrs->useless, &vrs->useless);
	vrs->walltextureup = mlx_xpm_file_to_image(vrs->mlx,
	vrs->rfilecub->icub->so, &vrs->widthtex, &vrs->heighttex);
	if (!vrs->walltextureup)
	{
		printf("invalid file XPM");
		return (0);
	}
	vrs->wallpointerup = (int*)mlx_get_data_addr(vrs->walltextureup,
	&vrs->useless, &vrs->useless, &vrs->useless);
	vrs->walltexturedown = mlx_xpm_file_to_image(vrs->mlx,
	vrs->rfilecub->icub->no, &vrs->widthtex, &vrs->heighttex);
	if (!vrs->walltexturedown)
	{
		printf("invalid file XPM");
		return (0);
	}
	vrs->wallpointerdown = (int*)mlx_get_data_addr(vrs->walltexturedown,
	&vrs->useless, &vrs->useless, &vrs->useless);
	vrs->texturesprit = mlx_xpm_file_to_image(vrs->mlx,
	vrs->rfilecub->icub->s, &vrs->widthtexsprit, &vrs->heighttexsprit);
	if (!vrs->texturesprit)
	{
		printf("invalid file XPM");
		return (0);
	}
	vrs->pointersprit = (int*)mlx_get_data_addr(vrs->texturesprit,
	&vrs->useless, &vrs->useless, &vrs->useless);
	return (1);
}

int		getstart(char *file, int b)
{
	t_data	*vrs;

	vrs = nvrbs();
	vrs->rfilecub = freadfile();
	if (!getinfo(vrs, file))
	{
		freeall(vrs->rfilecub);
		freevrs(vrs);
		exit(0);
		return (0);
	}
	if (!startandgetex(vrs))
	{
		freeall(vrs->rfilecub);
		freexit(vrs);
		exit(0);
		return (0);
	}
	call_functions(vrs);
	freeall(vrs->rfilecub);
	if (b == 1)
		screeen(vrs);
	my_mlx_hooks(vrs);
	return (1);
}
