/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:50:05 by yporoka           #+#    #+#             */
/*   Updated: 2018/08/07 17:12:40 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char		*ft_infection(int i, char *s)
{
	if (s[i + 1] == '#')
	{
		s[i + 1] = 'x';
		s = ft_infection(i + 1, s);
	}
	if (i - 1 >= 0 && s[i - 1] == '#')
	{
		s[i - 1] = 'x';
		s = ft_infection(i - 1, s);
	}
	if (i + 5 <= 20 && s[i + 5] == '#')
	{
		s[i + 5] = 'x';
		s = ft_infection(i + 5, s);
	}
	if (i - 5 >= 0 && s[i - 5] == '#')
	{
		s[i - 5] = 'x';
		s = ft_infection(i - 5, s);
	}
	if (s[i] == '#')
		s[i] = 'x';
	return (s);
}

static int		ft_count_x(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == 'x')
			i++;
		str++;
	}
	return (i);
}

void			ft_second_check(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '#')
		i++;
	s[i] = 'x';
	s = ft_infection(i, s);
	if (ft_count_x(s) < 4)
		ft_error();
	while (*s)
	{
		if (*s == 'x')
			*s = '#';
		s++;
	}
}

int				ft_first_check(char *str)
{
	int		dot;
	int		diese;
	int		endl;

	dot = 0;
	diese = 0;
	endl = 0;
	while (*str)
	{
		if (*str == '.')
			dot++;
		else if (*str == '#')
			diese++;
		else if (*str == '\n')
			endl++;
		else
			ft_error();
		str++;
	}
	if (diese < 4)
		ft_error();
	if ((dot % 4) || (diese % 4) || (endl + 1) % 5)
		ft_error();
	return (diese / 4);
}

int				ft_check_tetri(char **map, t_block *block, int size)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (block->y[i] < size && block->x[i] < size && \
					map[block->y[i]][block->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
