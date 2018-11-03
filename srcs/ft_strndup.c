/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yporoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:18:11 by yporoka           #+#    #+#             */
/*   Updated: 2018/07/02 18:54:05 by yporoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*fresh;

	if (!(fresh = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	fresh = ft_strncpy(fresh, s, n);
	fresh[n] = '\0';
	return (fresh);
}
