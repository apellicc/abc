/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 04:03:22 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/09 11:58:20 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place_tetri(char **map, char *save, int *coord, int max)
{
	int i;
	int y;
	int x;

	i = 0;
	y = coord[0];
	x = coord[1];
	while (i < 19)
	{
		ft_putendl("-----------------------------------");
		ft_putendl(" dans boucle de place");
		ft_putnbr(i);
		ft_putendl(" valeur de i");
		ft_putchar(save[i]);
		ft_putendl(" char save [i]");
		ft_putnbr(y);
		ft_putendl(" valeur y");
		ft_putnbr(x);
		ft_putendl(" valeur x");
		ft_putendl("-----------------------------------");

		if (save[i] == '\n')
		{
			i++;
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
		{
			if (save[i] != '.')
				map[y][x] = save[i];
			i++;
			x++;
		}
		ft_putendl("-----------------------------------");
		ft_putendl(" fin boucle de place");
		ft_puttab(map);
		ft_putendl("-----------------------------------");
		//sleep(1);
	}
	ft_putendl("apres boucle");
	return (0);
}
