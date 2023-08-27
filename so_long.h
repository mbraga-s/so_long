/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:50 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/27 13:14:50 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include "minilibx-linux/mlx.h"
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
}					t_all;

//main

t_all	*all(void);

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