/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:24 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/18 16:22:52 by mbraga-s         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;
	char	**temp;

	i = 0;
	if (argc == 2)
	{
		map = make_map(argv[1]);
		temp = dupmap(map);
		while (i < map.map_height)
		{
			printf("%s", temp[i]);
			i++;
		}
		map_free(map.maparray);
		map_free(temp);
	}
	return (0);
}
