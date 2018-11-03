/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:34:08 by yporoka           #+#    #+#             */
/*   Updated: 2018/08/06 11:40:03 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_block	*ft_block_xy(t_block *block, char **s)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				block->x[i] = x;
				block->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (block);
}

t_block			*ft_coord_xy(t_block *block)
{
	t_block		*tmp_first;

	tmp_first = block;
	while (block->next)
	{
		block = ft_block_xy(block, ft_strsplit(block->str, '\n'));
		free(block->str);
		block = block->next;
	}
	return (tmp_first);
}
