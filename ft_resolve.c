/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:22:58 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/09 11:55:45 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_resolve(char  **save, int nb_piece)
{
	int	    qrt;
	char 	**map;
	int		**coord;

	map = NULL;
	coord = NULL;
	qrt = ft_sqrt(nb_piece * 4);
	map = ft_mapalloc(map, qrt);
	if (!map)
		return NULL;
	coord = ft_ini_coord(nb_piece, coord);
	map = ft_backtrack(map, save, coord, qrt);
	ft_puttab(map);
	//ft_free_tab(save);
//	while (--nb_piece)
	//{
		//free(coord[nb_piece]);
	//}
	//free(coord);
	return (map);
}

char **ft_backtrack(char **map, char **save, int **coord, int max)
{
	int		i;
	int		rp;

	i = 0;
	while (save[i])
	{
		ft_putnbr(max);
		ft_putendl("valeur de max");
		rp = ft_place_tetri(map, save[i], coord[i], max);
		if (rp == 1)
		{
			ft_putendl("dans 1 er if soit y > max");
			ft_remove(map, 'A' + i);
			coord[i][0] = 0;
			coord[i][1] = 0;
			if (i == 0)
			{
				max++;
				map = ft_mapalloc(map, max);
			}
			else
			{

				i--;
				ft_remove(map, 'A' + i);
				coord[i][1]++;
			}
		}
		else if (rp == 2)
		{
			ft_putendl("dans 1 er else if soit x > max");
			ft_remove(map, 'A' + i);
			coord[i][0]++;
			coord[i][1] = 0;
		}
		else if (rp == 3)
		{
			ft_putendl("dans 2 eme else if soit copier de lettre sur lettre");
			ft_remove(map, 'A' + i);
			coord[i][1]++;
		}
		else
			i++;
	}
	return (map);
}
