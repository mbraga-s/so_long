/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:50 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/30 19:24:42 by mbraga-s         ###   ########.fr       */
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
	void		*win;
	void		*floor;
	void		*wall;
	void		*ur_c;
	void		*ul_c;
	void		*lr_c;
	void		*ll_c;
	void		*l_side;
	void		*r_side;
	void		*t_border;
	void		*b_border;
	void		*coll;
	void		*door;
	void		*p_id;
	void		*player_u;
	void		*player_d;
	void		*player_r;
	void		*player_l;
	void		*enemy;
	int			col_nbr;
	int			steps;

}					t_all;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

//so_long.c

t_all	*all(void);

void	set_img(t_all *imgs);

//checker.c

int		check_tpbm(t_map map);

int		check_side(t_map map);

int		check_shape(t_map map);

int		check_content(t_map map, char a);

int		checker(t_map map);

//path.c

t_pos	start_pos(char **tempmap);

void	flood_fill(char **tempmap, int x, int y, int *flag);

int		check_path(void);

char	**dupmap(void);

int		collect_catch(char **tempmap);

//map.c

int		map_getheight(char *path);

t_map	alloc_map(char *path);

t_map	make_map(char *path);

//moves.c

int		key_press(int a);

void	move(char **map, int x, int y);

int		check_collision(char **map, int x, int y, char c);

void	sprite(int x, int y);

void	show_steps(void);

//place_tiles.c

void	place_tiles(t_all imgs, char **map);

void	choose_tile(char a, int y, int x, t_all imgs);

void	wall_make(int x, int y, t_all imgs);

//free.c

int		end_game(void);

void	map_free(char **maparray);

#endif