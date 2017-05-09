/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:29:10 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/10 18:01:53 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include </usr/local/include/mlx.h>
# include <math.h>
# include "../../libft/includes/libft.h"

/*
** STRUCTURES
*/

typedef struct		s_lst
{
	int				**zc;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_pt
{
	int				x;
	int				y;
	int				z;
	unsigned char	c[4];
}					t_pt;

typedef struct		s_mlx
{
	void			*id;
	void			*win;
	void			*img;
	void			*cur;
	char			*dat;
	char			*file;
	int				w_dim[2];
	int				i_dim[3];
	int				cen[2];
	int				info[3];
	int				max[4];
	float			rot;
	float			coef[2];
	int				color;
	int				cur_val;
}					t_mlx;

typedef struct		s_data
{
	t_lst			*coord;
	t_mlx			mlx;
}					t_data;

/*
** MAIN FUNCTIONS
*/

void				ft_usage(void);
void				ft_error(const char *msg);
int					ft_fdf_valid_tab(char **tab);
t_lst				*ft_get_coord(char *file);
char				*ft_find_color(char *s);
void				ft_max(t_lst *coord, int *max);
void				ft_calibrate(int *dim, int *max, float *coef, int *info);
void				ft_init_center(int *c, int *max, float coef);
void				ft_center(int *cen, float ang, int dir);
char				*ft_fill_image(t_mlx mlx, t_lst *coord);
void				ft_clean(t_data *param);

/*
** UI
*/

char				*ft_filename(char *str);
t_pt				ft_grad(t_pt a, t_pt b, t_pt c);
unsigned int		ft_pt_color(int max, int z);
void				ft_cursor(t_mlx mlx);

/*
** EVENTS
*/

int					ft_key_input(int key, t_data *param);
int					ft_mouse_input(int button, int x, int y, t_data *param);
t_data				*ft_event_rot(int val, t_data *param);
t_data				*ft_event_move(int val, t_data *param);
t_data				*ft_event_size(int val, t_data *param);
t_data				*ft_event_color(int val, t_data *param);
t_data				*ft_event_cursor(t_data *param);

/*
** DISPLAYS
*/
void				ft_display(t_mlx mlx, t_lst *coord);
void				ft_disp_info(t_mlx mlx);
void				ft_disp_pos(t_mlx mlx, t_lst *coord);
void				ft_disp_move(t_mlx mlx);
void				ft_disp_rot(t_mlx mlx);
void				ft_disp_zoom(t_mlx mlx);
void				ft_disp_col(t_mlx mlx);
void				ft_disp_cur(t_mlx mlx);
void				ft_disp_exit(t_mlx mlx);
void				ft_info_zoom_z(t_mlx mlx);

#endif
