/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:36:45 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/30 14:31:56 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_pos	start_pos(char **tempmap)
{
	int		i;
	int		j;
	t_pos	temp;

	i = 0;
	temp.x = 0;
	temp.y = 0;
	while (tempmap[i])
	{
		j = 0;
		while (tempmap[i][j])
		{
			if (tempmap[i][j] == 'P')
			{
				temp.y = i;
				temp.x = j;
				return (temp);
			}
			j++;
		}
		i++;
	}
	return (temp);
}

void	flood_fill(char **tempmap, int w, int h, int *flag)
{
	//printf("Flood start at (%d, %d) with %c.\n", h, w, tempmap[h][w]);
	if (tempmap[h][w] == '1' || tempmap [h][w] == 'X' || tempmap[h][w] == 'V')
		return ;
	if (tempmap[h][w] == 'C' || tempmap[h][w] == '0' || tempmap[h][w] == 'P')
		tempmap[h][w] = 'V';
	if (tempmap[h][w] == 'E')
	{
		*flag = 0;
		return ;
	}
	//printf("Flood end at (%d,%d) with %c.\n", h, w, tempmap[h][w]);
	flood_fill(tempmap, (w + 1), h, flag);
	flood_fill(tempmap, (w - 1), h, flag);
	flood_fill(tempmap, w, (h + 1), flag);
	flood_fill(tempmap, w, (h - 1), flag);
}

int	check_path(void)
{
	int		flag;
	char	**tempmap;
	t_pos	coords;

	flag = 1;
	tempmap = dupmap();
	coords = start_pos(tempmap);
	//printf("Start (%d,%d)\n\n", coords.y, coords.x);
	flood_fill(tempmap, coords.x, coords.y, &flag);
	if (flag || collect_catch(tempmap))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid map\n", 2);
		map_free(tempmap);
		return (1);
	}
	map_free(tempmap);
	return (0);
}

char	**dupmap(void)
{
	char	**tempmap;
	char	*ptr;
	int		i;

	i = 0;
	tempmap = ft_calloc((*all()).map.map_height + 1, sizeof(char *));
	while (i < (*all()).map.map_height)
	{
		ptr = ft_calloc((*all()).map.map_width + 2, sizeof(char));
		ft_strlcpy(ptr, (*all()).map.maparray[i], (*all()).map.map_width + 2);
		tempmap[i] = ptr;
		i++;
	}
	tempmap[i] = NULL;
	return (tempmap);
}

int	collect_catch(char **tempmap)
{
	int	i;
	int	j;

	i = 0;
	while (tempmap[i])
	{
		j = 0;
		while (tempmap[i][j])
		{
			if (tempmap[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
