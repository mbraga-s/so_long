/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:57:44 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/29 14:55:54 by mbraga-s         ###   ########.fr       */
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

int	check_shape(t_map map)
{
	int	i;

	i = 0;
	while (i < (map.map_height - 1))
	{
		if (map.map_width != (ft_strlen_gnl(map.maparray[i]) - 1))
			return (0);
		i++;
	}
	if (map.map_width != (ft_strlen_gnl(map.maparray[i])))
		return (0);
	return (1);
}

int	check_content(t_map map, char a)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map.map_height)
	{
		j = 0;
		while (j < (map.map_width - 1))
		{
			if (map.maparray[i][j] == a)
				count++;
			if (map.maparray[i][j] != '0' && map.maparray[i][j] != '1' && \
					map.maparray[i][j] != 'P' && map.maparray[i][j] != 'C' && \
					map.maparray[i][j] != 'E' && map.maparray[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (count);
}

int	checker(t_map map)
{
	if (!check_shape(map))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map isn't a rectangle.\n", 2);
		return (1);
	}
	if (!check_side(map) || !check_tpbm(map))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map isn't surrounded by walls.\n", 2);
		return (1);
	}
	if (!check_content(map, 'C'))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map has invalid chars or lacks mandatory ones.\n", 2);
		return (1);
	}
	if (check_content(map, 'P') != 1 || check_content(map, 'E') != 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map has wrong number of players or exits.\n", 2);
		return (1);
	}
	return (0);
}
