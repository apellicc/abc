/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 20:45:05 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/05 03:34:04 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_mapalloc(char **map, int t)
{
	char	**newmap;
	int		i;
	
	i = -1;
	ft_putnbr(t);
	ft_putendl("num alloc  ");
	newmap = malloc(sizeof(char *) * (t + 1));
	ft_memset(newmap, '.', t);
	ft_putendl("------------------------");
	ft_putendl("new map");
	//ft_puttab(newmap);
	newmap[t] = NULL;
	while (++i < t)
	{
		newmap[i] = malloc(sizeof(char) * (t + 1));
		ft_putendl("avant bzero");
		ft_putendl("avant memset");
		ft_memset(newmap[i], '.', t);
		newmap[i][t] = '\0';
		//sleep(2);
	}
	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
	ft_puttab(newmap);
	ft_putendl("------------------------");
	return (newmap);
}

