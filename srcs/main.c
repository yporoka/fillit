/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:50:08 by yporoka           #+#    #+#             */
/*   Updated: 2018/08/07 18:12:36 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void		ft_check_dot(char *str)
{
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	while (i <= 20)
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (dot != 12)
		ft_error();
}

t_block		*ft_allocateblock(char *str)
{
	int		i;
	int		qt;
	char	c;
	t_block	*first;
	t_block	*tmp;

	i = 0;
	c = 'A';
	qt = ft_first_check(str);
	if (!(first = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	tmp = first;
	while (qt-- > 0)
	{
		tmp->str = ft_strndup(&str[i], 20);
		ft_check_dot(tmp->str);
		ft_second_check(tmp->str);
		tmp->c = c++;
		i += 21;
		if (!(tmp->next = (t_block *)malloc(sizeof(t_block))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (first);
}

char		*ft_readfile(char *file)
{
	char	tmp[545];
	int		fd;
	int		i;
	char	buffer[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while (read(fd, buffer, 1))
	{
		tmp[i++] = buffer[0];
		if (i > 545)
			ft_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

int			main(int argc, char **argv)
{
	t_block		*block;
	char		*read;

	if (argc == 2)
	{
		read = ft_readfile(argv[1]);
		block = ft_allocateblock(read);
		block = ft_coord_xy(block);
		ft_solve(block);
		free(block);
		free(read);
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
