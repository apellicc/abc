/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 04:03:22 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/06 04:04:31 by apellicc         ###   ########.fr       */
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
		if (save[i] == '\n')
		{
			y++;
			x = coord[1];
		}
		else if ((y > max || x > max) && save[i] != '.')
			{
				ft_putnbr(y);
				ft_putendl("valeur de y dans return 1");
				ft_putnbr(x);
				ft_putendl("valeur de x");
				sleep(2);	
				return (1);
			}
		else if (save[i] != '.' && map[y][x] != '.')
		{
			ft_putnbr(y);
				ft_putendl("valeur de y dans return 2");
				ft_putnbr(x);
				ft_putendl("valeur de x");
				sleep(2);	
			return (2);
		}
		else if (map[y][x] == '.')
		{
			if (save[i] != '.')
				map[y][x] = save[i];
			x++;
		}
		i++;
	}
	return (0);
}

void	ft_remove(char **map, char c)
{
	int x;
	int y;

	y = -1;
	while (map[++y])
	{
		ft_putnbr(y);
		ft_putendl("valeur de y dans remove");
		
		x = -1;
		while (map[y][++x])
		{
			ft_putnbr(x);
			ft_putendl("valeur de x");
			if (map[y][x] == c)
				map[y][x] = '.';
		}
	}
	ft_putendl("apres remove");
}
