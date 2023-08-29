/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:16:22 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/29 15:41:47 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_tiles(t_all imgs, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			choose_tile(map[i][j], i, j, imgs);
			i++;
		}
		j++;
	}
	show_steps();
}
//check if x and y don't need to switch

void	choose_tile(char a, int x, int y, t_all imgs)
{
	if (a == '1')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.wall, x * 64, y * 64);
	if (a == '0')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.floor, x * 64, y * 64);
	if (a == 'E')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.door, x * 64, y * 64);
	if (a == 'C')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.coll, x * 64, y * 64);
	if (a == 'P')
		mlx_put_image_to_window(imgs.mlx, imgs.win, imgs.p_id, x * 64, y * 64);
}
