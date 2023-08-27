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

void	p_up(t_map map, int w, int h)
{
	if (map.maparray[h + 1][w] == 1)
		return ;
	map.maparray[h][w] = '0';
	map.maparray[h + 1][w] = 'P';
}
