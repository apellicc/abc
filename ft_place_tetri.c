/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 04:03:22 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/11 03:05:44 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_else(char **map, char savei, int y, int *x)
{
	if (savei != '.')
		map[y][*x] = savei;
	*x += 1;
}

int			ft_place_tetri(char **map, char *save, int *coord, int max)
{
	int i;
	int y;
	int x;

	i = -1;
	y = coord[0];
	x = coord[1];
	while (++i < 19)
	{
		if (save[i] == '\n')
		{
			y++;
			x = coord[1];
		}
		else if (y == max && save[i] != '.')
			return (1);
		else if (x == max && save[i] != '.')
			return (2);
		else if (save[i] != '.' && map[y][x] != '.')
			return (3);
		else
			ft_else(map, save[i], y, &x);
	}
	return (0);
}
