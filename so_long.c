/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:24 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/29 11:55:25 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_loop(mlx);
	return (0);
} */

t_all	*all(void)
{
	static t_all	all;

	return (&all);
}

void	set_img(t_all *imgs)
{
	int	i;

	imgs->floor = mlx_xpm_file_to_image(imgs->mlx, "floor.xpm", &i, &i);
	imgs->collec = mlx_xpm_file_to_image(imgs->mlx, "collectable.xpm", &i, &i);
	imgs->wall = mlx_xpm_file_to_image(imgs->mlx, "wall.xpm", &i, &i);
	imgs->door = mlx_xpm_file_to_image(imgs->mlx, "sleigh.xpm", &i, &i);
	imgs->player_d = mlx_xpm_file_to_image(imgs->mlx, "player_d.xpm", &i, &i);
	imgs->player_l = mlx_xpm_file_to_image(imgs->mlx, "player_l.xpm", &i, &i);
	imgs->player_r = mlx_xpm_file_to_image(imgs->mlx, "player_r.xpm", &i, &i);
	imgs->player_u = mlx_xpm_file_to_image(imgs->mlx, "player_u.xpm", &i, &i);
	imgs->player_idle = imgs->player_d;
	imgs->enemy = mlx_xpm_file_to_image(imgs->mlx, "placeholder_hole.xpm", &i, &i);
	imgs->col_nbr = check_content((imgs->map), "C");
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		ft_putchar_fd("Error - Invalid number of args.\n", 2);
		return (0);
	}
	(*all()).map = make_map(argv[1]); //check syntax on (*all())
	(*all()).mlx = mlx_init();
	set_img(all());
	(*all()).window = mlx_new_window((*all()).mlx, (*all()).map.map_width * 64,
			(*all()).map.map_height * 64, "so_long");
	
}
