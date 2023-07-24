/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraga-s <mbraga-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:28:50 by mbraga-s          #+#    #+#             */
/*   Updated: 2023/07/24 16:55:57 by mbraga-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int			map_height;
	int			map_width;
	char		**maparray;
}					t_map;

void	ft_putstr_fd(char *s, int fd);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *str);

#endif
