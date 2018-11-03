/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:00:10 by yporoka           #+#    #+#             */
/*   Updated: 2018/08/06 12:14:57 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**ft_remove_tetri(char **map, t_block *block, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == block->c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char	**ft_insert_tetri(char **map, t_block *block, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (block->y[i] == y && block->x[i] == x)
			{
				map[y][x] = block->c;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

void	ft_print_map(char **map)
{
	int i;

	if (map == NULL)
		ft_error();
	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
