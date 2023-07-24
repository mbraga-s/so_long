/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:57:44 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/24 17:56:21 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lines(int fd)
{
	int		i;
	int		count;
	char	*ptr;

	i = 0;
	count = 0;
	while (i == 0)
	{
		ptr = get_next_line(fd);
		if (!ptr)
			i = 1;
		count++;
	}
	return (count);
}

int	check_tpbm(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != 1)
		{
			j = 1;
			break ;
		}
		i++;
	}
	return (j);
}

int	checker(void)
{
	int		fd;
	char	*ptr;
	int		count;
	int		f;

	fd = open("map", O_RDONLY);
	count = lines(fd);
	fd = open("map", O_RDONLY);
	printf("%d\n", count);
	f = count;
	while (f >= 0)
	{
		ptr = get_next_line(fd);
		printf("%s\n", ptr);
		if (f == count)
		{
			if (check_tpbm(ptr) == 1)
			{
				printf("Invalid map\n");
				break ;
			}
		}
		else if (f == 0)
		{
			if (check_tpbm(ptr) == 1)
			{
				printf("Invalid map\n");
				break ;
			}
		}
		f--;
	}
	printf("LINES = %d\n", count);
	return (0);
}

int	main(void)
{
	checker();
	return (0);
}
