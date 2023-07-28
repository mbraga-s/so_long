/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:57:44 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/26 17:15:26 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_tpbm(t_map map)
{
	int	i;

	i = 0;
	while (i < (map.map_width - 1))
	{
		if (map.maparray[0][i] != '1')
			return (0);
		else if (map.maparray[map.map_height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_side(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_height)
	{
		if (map.maparray[i][0] != '1')
			return (0);
		if (map.maparray[i][map.map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checker(t_map map)
{
	if (!check_side(map) || !check_tpbm(map))
	{
		ft_putstr_fd("Error\nMap isn't surrounded by walls.\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map = make_map(argv[1]);
		(void) map;
	}
	return (0);
}
