/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:11:27 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/30 14:28:57 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(void)
{
	mlx_destroy_image((*all()).mlx, (*all()).wall);
	mlx_destroy_image((*all()).mlx, (*all()).floor);
	mlx_destroy_image((*all()).mlx, (*all()).player_d);
	mlx_destroy_image((*all()).mlx, (*all()).player_l);
	mlx_destroy_image((*all()).mlx, (*all()).player_r);
	mlx_destroy_image((*all()).mlx, (*all()).player_u);
	mlx_destroy_image((*all()).mlx, (*all()).coll);
	mlx_destroy_image((*all()).mlx, (*all()).door);
	/* mlx_destroy_image((*all()).mlx, (*all()).ur_corner);
	mlx_destroy_image((*all()).mlx, (*all()).ul_corner);
	mlx_destroy_image((*all()).mlx, (*all()).lr_corner);
	mlx_destroy_image((*all()).mlx, (*all()).ll_corner);
	mlx_destroy_image((*all()).mlx, (*all()).side_border);
	mlx_destroy_image((*all()).mlx, (*all()).tb_border); */
	if (check_content((*all()).map, 'X'))
		mlx_destroy_image((*all()).mlx, (*all()).enemy);
	map_free(((*all()).map.maparray));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	mlx_destroy_display((*all()).mlx);
	free((*all()).mlx);
	exit(0);
}

void	map_free(char **maparray)
{
	int	i;

	i = 0;
	while (maparray[i])
	{
		free(maparray[i]);
		i++;
	}
	free(maparray);
}
