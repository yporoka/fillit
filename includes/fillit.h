/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:23:18 by yporoka           #+#    #+#             */
/*   Updated: 2018/08/07 17:16:59 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_block
{
	char			c;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_block	*next;
}					t_block;

char				*ft_readfile(char *file);
t_block				*ft_allocateblock(char *str);
void				ft_error(void);
int					ft_first_check(char *str);
void				ft_second_check(char *s);
void				ft_putendl(char const *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s, size_t n);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				**ft_strsplit(char const *s, char c);
int					ft_countwords(char const *s, char c);
size_t				ft_sqrt(size_t nb);
char				**ft_create_map(char **map, int map_size);
t_block				*ft_coord_xy(t_block *block);
char				**ft_remove_tetri(char **map, t_block *block, int size);
char				**ft_insert_tetri(char **map, t_block *block, int size);
void				ft_print_map(char **map);
void				ft_solve(t_block *block);
char				**ft_algo(char	**tetri_map, t_block *block, int map_size);
int					ft_check_tetri(char	**map, t_block *block, int size);
void				ft_memdel(void **ap);
void				ft_check_dot(char *str);

#endif
