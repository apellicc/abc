/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 20:45:05 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/12 11:35:03 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_mapalloc(char **map, int t)
{
	char	**newmap;
	int		i;

	i = -1;
	newmap = malloc(sizeof(char *) * (t + 1));
	ft_memset(newmap, '.', t);
	newmap[t] = NULL;
	while (++i < t)
	{
		newmap[i] = malloc(sizeof(char) * (t + 1));
		ft_memset(newmap[i], '.', t);
		newmap[i][t] = '\0';
	}
	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
	return (newmap);
}
