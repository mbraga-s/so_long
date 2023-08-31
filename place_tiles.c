/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:16:22 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/31 21:38:33 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_tiles(t_all imgs, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*all()).map.map_height)
	{
		j = 0;
		while (j < (*all()).map.map_width)
		{
			choose_tile(map[i][j], i, j, imgs);
			j++;
		}
		i++;
	}
	show_steps();
}

void	choose_tile(char a, int y, int x, t_all imgs)
{
	if (a == '1')
		wall_make(x, y, imgs);
	if (a == '0')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.floor, x * 64, y * 64);
	if (a == 'E')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.door, x * 64, y * 64);
	if (a == 'C')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.coll, x * 64, y * 64);
	if (a == 'P')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.p_id, x * 64, y * 64);
	if (a == 'X')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.enemy, x * 64, y * 64);
}

void	wall_make(int x, int y, t_all imgs)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.ul_c, x * 64, y * 64);
	else if (y == 0 && x == ((*all()).map.map_width - 1))
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.ur_c, x * 64, y * 64);
	else if (y == ((*all()).map.map_height - 1) && x == 0)
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.ll_c, x * 64, y * 64);
	else if (y == ((*all()).map.map_height - 1) && \
			x == ((*all()).map.map_width - 1))
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.lr_c, x * 64, y * 64);
	else if (y == 0)
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.t_bo, x * 64, y * 64);
	else if (y == ((*all()).map.map_height - 1))
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.b_bo, x * 64, y * 64);
	else if (x == 0)
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.l_si, x * 64, y * 64);
	else if (x == ((*all()).map.map_width - 1))
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.r_si, x * 64, y * 64);
	else
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.wall, x * 64, y * 64);
}
