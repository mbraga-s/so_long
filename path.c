/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:36:45 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/27 12:28:43 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	start_pos(int *w, int *h, char **tempmap)
{
	int	i;
	int	j;

	i = 0;
	while (tempmap[i])
	{
		j = 0;
		while (tempmap[i][j])
		{
			if (tempmap[i][j] == 'P')
			{
				*h = i;
				*w = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **tempmap, int w, int h, int *flag)
{
	//printf("Flood start at (%d, %d) with %c.\n", h, w, tempmap[h][w]);
	if (tempmap[h][w] == '1' || tempmap[h][w] == 'V')
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
	int		w;
	int		h;
	int		flag;
	char	**tempmap;

	flag = 1;
	w = 0;
	h = 0;
	tempmap = dupmap();
	printf("%s", tempmap[0]);
	start_pos(&w, &h, tempmap);
	printf("Start (%d,%d)\n\n", h, w);
	flood_fill(tempmap, w, h, &flag);
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
