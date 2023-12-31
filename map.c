/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:24:26 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/10/02 14:19:42 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_getheight(char *path)
{
	int		fd;
	int		count;
	char	buffer;

	count = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid file descriptor...\n", 2);
		exit(1);
	}
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			count++;
	}
	close(fd);
	return (count);
}

t_map	alloc_map(char *path)
{
	t_map	map;
	int		i;
	int		fd;

	i = 0;
	map.map_height = map_getheight(path);
	map.maparray = malloc((map.map_height + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (!map.maparray || fd < 0 || map.map_height <= 2)
	{
		ft_putstr_fd("Error\nError allocating map space...\n", 2);
		close(fd);
		map_free(map.maparray);
		exit(1);
	}
	while (map.map_height > i)
	{
		map.maparray[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map.maparray[i] = NULL;
	map.map_width = ft_strlen(map.maparray[0]) - 1;
	return (map);
}

t_map	make_map(char *path)
{
	t_map	map;

	if (ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid map file type...\n", 2);
		exit(1);
	}
	map = alloc_map(path);
	if (checker(map))
	{
		map_free(map.maparray);
		exit(1);
	}
	return (map);
}
