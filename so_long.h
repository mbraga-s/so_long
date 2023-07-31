/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:50 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/31 12:45:17 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./getnextline/get_next_line.h"
# include <fcntl.h>

typedef struct s_map
{
	int			map_height;
	int			map_width;
	char		**maparray;
}					t_map;

int		checker(t_map map);

int		check_content(t_map map, char a);

int		check_shape(t_map map);

int		check_side(t_map map);

int		check_tpbm(t_map map);

int		map_getheight(char *path);

t_map	alloc_map(char *path);

t_map	make_map(char *path);

void	map_free(char **maparray);

#endif
