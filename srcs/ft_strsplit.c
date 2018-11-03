/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:09:06 by yporoka           #+#    #+#             */
/*   Updated: 2018/07/02 19:54:12 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char	**ft_support(char **fresh, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			fresh[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	fresh[k] = NULL;
	return (fresh);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fresh;

	if (s == NULL)
		return (NULL);
	if (!(fresh = (char **)malloc(sizeof(char *) * (ft_countwords(s, c)) + 1)))
		return (NULL);
	return (ft_support(fresh, s, c));
}
