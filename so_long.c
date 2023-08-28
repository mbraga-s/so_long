/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:24 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/28 15:37:27 by mbraga-s         ###   ########.fr       */
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
	if (check_path())
		return (0);
	while (i < (*all()).map.map_height)
	{
		printf("%s", (*all()).map.maparray[i]);
		i++;
	}
	map_free((*all()).map.maparray);
	return (0);
}
