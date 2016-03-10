/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:22:58 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/10 21:52:10 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_resolve(char **save, int nb_piece)
{
	int		qrt;
	char	**map;
	int		**coord;

	map = NULL;
	coord = NULL;
	qrt = ft_sqrt(nb_piece * 4);
	map = ft_mapalloc(map, qrt);
	if (!map)
		return (NULL);
	coord = ft_ini_coord(nb_piece, coord);
	map = ft_backtrack(map, save, coord, qrt);
	ft_puttab(map);
	ft_free_tab(save);
	while (--nb_piece >= 0)
	{
		free(coord[nb_piece]);
	}
	free(coord);
	return (map);
}

char	**ft_backtrack(char **map, char **save, int **coord, int max)
{
	int		i;
	int		rp;

	i = 0;
	while (save[i])
	{
		rp = ft_place_tetri(map, save[i], coord[i], max);
		if (rp != 0)
			ft_remove(map, 'A' + i);
		if (rp == 1)
			map = ft_rp1(coord, &max, &i, map);
		else if (rp == 2)
		{
			coord[i][0]++;
			coord[i][1] = 0;
		}
		else if (rp == 3)
			coord[i][1]++;
		else
			i++;
	}
	return (map);
}
