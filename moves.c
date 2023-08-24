#include "so_long.h"

void	p_up(t_map map, int w, int h)
{
	if (map.maparray[h + 1][w] == 1)
		return ;
	map.maparray[h][w] = '0';
	map.maparray[h + 1][w] = 'P';
}
