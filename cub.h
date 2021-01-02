/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:23:22 by fbouibao          #+#    #+#             */
/*   Updated: 2020/12/28 16:25:21 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <limits.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "ft_printf/ft_printf.h"
# include "cub/cub3d.h"
# include "cub/get_next_line/get_next_line.h"
# define PI 3.14159265
# define TWO_PI 6.28318530
# define TILE_SIZE 64
# define M_S_F 0.2
# define FOV_ANGLE (60 * (PI / 180))

typedef struct		s_util3d {
	float			crtdist;
	float			disteprjpln;
	float			pjctedwllhght;
	int				wllstrphght;
	int				wtoppxl;
	int				wbopxl;
	int				y;
	int				texelcolor;
	int				texofsetx;
	int				distfrmt;
	int				texofsy;
}					t_util3d;

typedef struct		s_sprit {
	int				id;
	int				i;
	int				j;
	float			xsprit;
	float			ysprit;
	float			distance;
	float			centredist;
	float			centrex;
	float			centrey;
	float			xshit;
	float			yshit;
	int				wasvert;
	struct s_sprit	*next;
}					t_sprit;

typedef struct		s_rayvars {
	float			rayangle;
	int				isrfd;
	int				isrfu;
	int				isrfr;
	int				isrfl;
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	int				foundhwh;
	float			hwhx;
	float			hwhy;
	float			shx;
	float			shy;
	float			xtocheck;
	float			ytocheck;
	int				foundvwh;
	int				foundvsh;
	float			vwhx;
	float			vwhy;
	float			nhtx;
	float			nhty;
	float			nvtx;
	float			nvty;
	float			hhd;
	float			vhd;
	t_sprit			*tmp;
	t_sprit			*tmp2;
}					t_rayvars;

typedef struct		s_player {
	float			x;
	float			y;
	float			width;
	float			height;
	int				turndirection;
	int				walkdirection;
	float			rotationangle;
	float			walkspeed;
	float			turnspeed;
	int				walkleft;
	int				walkright;
}					t_player;

typedef struct		s_ray {
	float			rayangle;
	float			wallhitx;
	float			wallhity;
	float			distance;
	int				washitvertical;
	int				wasprhitvert;
	int				israyfacingup;
	int				israyfacingdown;
	int				israyfacingleft;
	int				israyfacingright;
	int				washitsprit;
	float			centrexsprit;
	float			xsprit;
	float			ysprit;
	float			distsprit;
	t_sprit			*sprit;
}					t_ray;

typedef struct		s_data {
	void			*mlx;
	void			*mlx_win;
	int				useless;
	int				widthtex;
	int				heighttex;
	int				num_rays;
	int				win_width;
	int				win_height;
	int				cpt;
	int				bigrow;
	int				mapwidth;
	int				mapheight;
	int				ceilcolor;
	int				floorcolor;
	int				widthtexsprit;
	int				heighttexsprit;
	void			*img;
	int				*frame;
	int				posibric;
	int				posjbric;
	char			**maps;
	t_player		*player;
	t_ray			**ray;
	void			*walltextureright;
	int				*wallpointerright;
	void			*walltextureleft;
	int				*wallpointerleft;
	void			*walltextureup;
	int				*wallpointerup;
	void			*walltexturedown;
	int				*wallpointerdown;
	void			*texturesprit;
	int				*pointersprit;
	float			ctrrayanglspt;
	int				i;
	int				j;
	t_rayvars		rayvars;
	t_util3d		util;
	t_filecub		*rfilecub;
}					t_data;

char				*ft_substr_o(char const *s, unsigned int start, int len);
void				ft_lstadd_back2(t_filecub *a, char *str);
char				*ft_substr2(char *s, unsigned int start);
char				*ft_substr3(char *s, unsigned int start);
int					ft_isdigit2(int c);
int					ft_atoi2(const char *c, int i);
void				horizray(t_data *vrs, float rayangle, int iray);
void				vertray(t_data *vrs, int iray);
void				castallrays(t_data *vrs);
float				normalizeangle(float angle);
int					checkwallray(t_data *vrs, float x, float y);
int					checkwall(t_data *vrs, float x, float y);
int					checksprit(t_data *vrs, float x, float y);
float				distbtnpts(float x1, float y1, float x2, float y2);
void				mdf_dist(t_data *vrs, t_rayvars rayvars,
		int iray, t_sprit *tmp);
void				prpsprit(t_data *vrs, t_rayvars rayvars, int iray);
void				get_player_pos(t_data *vrs);
t_filecub			*freadfile();
int					readfromfile(t_filecub *rfilecub, char *file);
void				errorfunc(int ernumber);
void				screeen(t_data *vrs);
void				updateplayerpos(t_data *vrs);
void				walk(t_data *vrs);
void				walkside(t_data *vrs, int leftright);
t_data				*nvrbs();
t_player			*setup();
t_ray				*new_ray();
t_sprit				*new_sprit();
void				free_rays(t_data *vrs);
void				freeall(t_filecub *rfcub);
void				freexit(t_data *vrs);
void				freevrs(t_data *vrs);
void				draw_3dproj(t_data *vrs);
void				util3d(t_data *vrs, int i);
void				render_ceil_floor(t_data *vrs, int i);
void				render_wall(t_data *vrs, int i);
void				render_w_s(t_data *vrs, int i);
void				initialplr(t_data *vrs);
int					getstart(char *file, int b);
int					getinfo(t_data *vrs, char *file);
void				my_mlx_hooks(t_data *vrs);
void				call_functions(t_data *vrs);
void				spritview(t_data *vrs, int i, t_sprit *sprit);
#endif
