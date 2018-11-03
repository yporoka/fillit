/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:19:26 by yporoka           #+#    #+#             */
/*   Updated: 2018/08/07 17:08:22 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**ft_create_map(char **map, int map_size)
{
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (map_size + 1))))
		return (NULL);
	while (i < map_size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (map_size + 1))))
			return (NULL);
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_xy_tetri(t_block **block, int x, int y)
{
	int		pos_x;
	int		pos_y;
	int		i;

	i = 0;
	pos_x = 100;
	pos_y = 100;
	while (i < 4)
	{
		if ((*block)->x[i] < pos_x)
			pos_x = (*block)->x[i];
		if ((*block)->y[i] < pos_y)
			pos_y = (*block)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*block)->x[i] = (*block)->x[i] - pos_x + x;
		(*block)->y[i] = (*block)->y[i] - pos_y + y;
		i--;
	}
}

char	**ft_algo(char **tetri_map, t_block *block, int size)
{
	int		x;
	int		y;
	char	**map;

	map = NULL;
	y = 0;
	if (block->next == NULL)
		return (tetri_map);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_xy_tetri(&block, x, y);
			if (ft_check_tetri(tetri_map, block, size))
				map = ft_algo(ft_insert_tetri(tetri_map, block, size), \
						block->next, size);
			if (map)
				return (map);
			tetri_map = ft_remove_tetri(tetri_map, block, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	ft_solve(t_block *block)
{
	char	**tetri_map;
	char	**result;
	int		map_size;

	map_size = 2;
	tetri_map = NULL;
	tetri_map = ft_create_map(tetri_map, map_size);
	result = NULL;
	while (!(result = ft_algo(tetri_map, block, map_size)))
	{
		map_size++;
		ft_memdel((void **)tetri_map);
		tetri_map = ft_create_map(tetri_map, map_size);
	}
	ft_print_map(result);
}
