/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:24 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/30 22:17:36 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

void	set_img(t_all *imgs)
{
	int	i;

	imgs->floor = mlx_xpm_file_to_image(imgs->mlx, "imgs/floor.xpm", &i, &i);
	imgs->coll = mlx_xpm_file_to_image(imgs->mlx, "imgs/collec.xpm", &i, &i);
	imgs->wall = mlx_xpm_file_to_image(imgs->mlx, "imgs/wall1.xpm", &i, &i);
	imgs->door = mlx_xpm_file_to_image(imgs->mlx, "imgs/sleigh.xpm", &i, &i);
	imgs->player_d = mlx_xpm_file_to_image(imgs->mlx, "imgs/pl_d.xpm", &i, &i);
	imgs->player_l = mlx_xpm_file_to_image(imgs->mlx, "imgs/pl_l.xpm", &i, &i);
	imgs->player_r = mlx_xpm_file_to_image(imgs->mlx, "imgs/pl_r.xpm", &i, &i);
	imgs->player_u = mlx_xpm_file_to_image(imgs->mlx, "imgs/pl_u.xpm", &i, &i);
	imgs->ur_c = mlx_xpm_file_to_image(imgs->mlx, "imgs/ur_corner.xpm", &i, &i);
	imgs->ul_c = mlx_xpm_file_to_image(imgs->mlx, "imgs/ul_corner.xpm", &i, &i);
	imgs->lr_c = mlx_xpm_file_to_image(imgs->mlx, "imgs/lr_corner.xpm", &i, &i);
	imgs->ll_c = mlx_xpm_file_to_image(imgs->mlx, "imgs/ll_corner.xpm", &i, &i);
	imgs->l_side = mlx_xpm_file_to_image(imgs->mlx, "imgs/l_side.xpm", &i, &i);
	imgs->r_side = mlx_xpm_file_to_image(imgs->mlx, "imgs/r_side.xpm", &i, &i);
	imgs->t_border = mlx_xpm_file_to_image(imgs->mlx, "imgs/top.xpm", &i, &i);
	imgs->b_border = mlx_xpm_file_to_image(imgs->mlx, "imgs/bott.xpm", &i, &i);
	imgs->p_id = imgs->player_d;
	imgs->enemy = mlx_xpm_file_to_image(imgs->mlx, "imgs/ph_hole.xpm", &i, &i);
	imgs->col_nbr = check_content((imgs->map), 'C');
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error - Invalid number of args.\n", 2);
		return (0);
	}
	(*all()).map = make_map(argv[1]); //check syntax on (*all())
	if (check_path())
		return (1);
	ft_putstr_fd("Valid map, initializing...\n", 1);
	(*all()).mlx = mlx_init();
	set_img(all());
	(*all()).win = mlx_new_window((*all()).mlx, ((*all()).map.map_width * 64),
			((*all()).map.map_height * 64), "so_long");
	mlx_hook((*all()).win, 17, 1, end_game, NULL);
	mlx_hook((*all()).win, 2, 1L << 0, key_press, NULL);
	place_tiles((*all()), (*all()).map.maparray);
	mlx_loop((*all()).mlx);
	return (0);
}
