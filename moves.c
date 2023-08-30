/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:10:35 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/08/24 22:10:35 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int a)
{
	if (a == XK_Escape)
		end_game();
	else if (a == XK_w)
		move((*all()).map.maparray, 0, -1);
	else if (a == XK_a)
		move((*all()).map.maparray, -1, 0);
	else if (a == XK_s)
		move((*all()).map.maparray, 0, 1);
	else if (a == XK_d)
		move((*all()).map.maparray, 1, 0);
	mlx_clear_window((*all()).mlx, (*all()).win);
	place_tiles((*all()), (*all()).map.maparray);
	return (1);
}

void	move(char **map, int x, int y)
{
	t_pos	coords;

	coords = start_pos(map);
	sprite(x, y);
	if (check_collision(map, x, y, 'E') && (*all()).col_nbr == 0)
	{
		ft_putstr_fd("You saved Christmas! Congratulations!\n", 1);
		end_game();
	}
	if (check_collision(map, x, y, 'X'))
	{
		ft_putstr_fd("Santa got hurt... Try again!\n", 1);
		end_game();
	}
	if (!check_collision(map, x, y, 'X') && !check_collision(map, x, y, '1'))
	{
		if (check_collision(map, x, y, 'C'))
			(*all()).col_nbr--;
		if (!check_collision(map, x, y, 'E'))
		{
			map[coords.y][coords.x] = '0';
			map[coords.y + y][coords.x + x] = 'P';
			(*all()).steps++;
		}
	}
}

int	check_collision(char **map, int x, int y, char c)
{
	t_pos	coords;

	coords = start_pos(map);
	if (map[coords.y + y][coords.x + x] == c)
		return (1);
	return (0);
}

void	sprite(int x, int y)
{
	if (x > 0)
		(*all()).p_id = (*all()).player_r;
	else if (x < 0)
		(*all()).p_id = (*all()).player_l;
	else if (y > 0)
		(*all()).p_id = (*all()).player_d;
	else if (y < 0)
		(*all()).p_id = (*all()).player_u;
}

void	show_steps(void)
{
	char	*steps;
	char	*str;

	steps = ft_itoa((*all()).steps);
	str = ft_strjoin("Steps taken: ", steps);
	mlx_string_put((*all()).mlx, (*all()).win, 50, 50, 0x00000000, str);
	free(steps);
	free(str);
}
