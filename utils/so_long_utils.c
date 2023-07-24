/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:36:45 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/24 18:03:47 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return (0);
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	ptr1;
	unsigned char	ptr2;
	size_t			i;

	i = 0;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	if (i == n)
		i--;
	ptr1 = s1[i];
	ptr2 = s2[i];
	return (ptr1 - ptr2);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	map_free(char **maparray)
{
	int	i;

	i = 0;
	while (maparray[i])
	{
		free(maparray[i]);
		i++;
	}
	free(maparray);
}
