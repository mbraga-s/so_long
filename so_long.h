/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:50 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/28 15:27:18 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

//structs

typedef struct s_map
{
	int			map_height;
	int			map_width;
	char		**maparray;
}					t_map;

typedef struct s_all
{
	t_map		map;
	void		*mlx;
	void		*window;
	void		*floor;
	void		*wall;
	void		*ur_corner;
	void		*ul_corner;
	void		*lr_corner;
	void		*ll_corner;
	void		*side_border;
	void		*tb_border;
	void		*collec;
	void		*door;
	void		*player_idle;
	void		*player_u;
	void		*player_d;
	void		*player_r;
	void		*player_l;
	void		*enemy;
	int			col_nbr;

}					t_all;

//main

t_all	*all(void);
void	set_img(t_all *imgs);

//checker

int		checker(t_map map);

int		check_content(t_map map, char a);

int		check_shape(t_map map);

int		check_side(t_map map);

int		check_tpbm(t_map map);

int		check_path(void);

void	flood_fill(char **tempmap, int x, int y, int *flag);

char	**dupmap(void);

void	start_pos(int *x, int *y, char **tempmap);

int		collect_catch(char **tempmap);

//map creation

int		map_getheight(char *path);

t_map	alloc_map(char *path);

t_map	make_map(char *path);

//Map free

void	map_free(char **maparray);

#endif