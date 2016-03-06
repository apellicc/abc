/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:29:21 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/05 05:55:14 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_algo(char **save)
{
	int	    qrt;
	char 	**map;
	int		i;
	
	map = NULL;
	i = ft_tablen(save);
	 ft_putnbr(i);
	qrt = ft_sqrt(i * 4);
	 ft_putnbr(qrt);
	 ft_putendl("debut algo, mapalloc");
	map = ft_mapalloc(map, qrt);
	if (!map)
		return NULL;
	ft_putendl("avant backtack");
	map = ft_backtrack(map, save, qrt);	
	return (map);
}
char	**ft_backtrack(char **map, char **save, int max)
{
	int i;
	int **coord;
	int rp;
	int rm;

	i = 0;
	// ft_putendl("avant 1 er ini");
	coord = ft_ini_coord(save);

	while (save[i] != NULL)
	{
		//ft_putendl("dans boucle, avant place");
		rp = ft_place_tetri(map, save[i], coord[i], max - 1);
		if (rp == 0)
			i++;
		else if (rp == 1)
		{
			// ft_putendl("avant remove");
			ft_remove(map, 'A' + i);
			// ft_putnbr(coord[i][1]);
			// ft_putendl("valeur de x avant");
			coord[i][1]++;
			// ft_putnbr(coord[i][1]);
			// ft_putendl("valeur de x apres ");

		}
		else
		{
			ft_putnbr(max);

			ft_putendl("valeur de max, avant inc ");

			rm = inc_max(coord[i], max - 1, i);
		 ft_putnbr(coord[i][0]);
		 ft_putchar('!');
		 ft_putnbr(coord[i][1]);
		 ft_putendl("apres inc ");

			ft_remove(map, 'A' + i);
			if (rm == 1)
			{
				ft_putnbr(max);
				ft_putendl("valeur max, dans if rm=1");
				max++;
				map = ft_mapalloc(map, max);
			}
			else if (rm == 2)
			{
				ft_putendl("dans else if, rm=2");				
				coord[i][1]++;
				i--;
				ft_remove(map, 'A' + i);
			}
			else
			{
				ft_putendl("dans else, rm=0");				
				coord[i][1]++;
			}
		}
	}
	return (map);
}

void	ft_remove(char **map, char c)
{
	int x;
	int y;

	y = 0;
	// ft_putendl("dans remove");
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int	inc_max(int *coord, int max, int i)
{
	ft_putnbr(coord[0]);
	ft_putendl("valeur de y debut inc");
	ft_putnbr(coord[1]);
	ft_putendl("valeur de x debut inc");
	ft_putnbr(max);
	ft_putendl("valeur de max debut inc");
	if (coord[0] >= max)
	{
		coord[0] = 0;
		coord[1] = 0;

		if (i == 0)
			return (1);
		else
			return (2);
	}
	else if (coord[1] >= max)
	{
		// ft_putnbr(coord[0]);
		ft_putchar('!');
		ft_putnbr(coord[1]);
		ft_putendl("dans inc ");
		coord[0]++;
		coord[1] = -1 ;
		ft_putnbr(coord[1]);
		ft_putendl(" ");
	}
	return (0);
}

int		ft_place_tetri(char **map, char *save, int *coord, int max)
{
	int i;
	int y;
	int x;
	int tour = 0;

	y = coord[0];
	x = coord[1];
	ft_putendl("------------------------------------");
	ft_putnbr(x);
	ft_putendl("valeur coord[1] soit x");
	ft_putendl("------------------------------------");
	i = 0;
	//ft_puttab(map);

	// ft_putendl("debut place");
	// ft_putendl(save);
	//ft_puttab(map);
	while (i < 19 )
	{
		tour++;
		ft_putendl("------------------------------------");
		ft_putnbr(tour);
		ft_putendl(" :tour numero ");

		ft_putnbr(y);
		ft_putendl(" valeur y");
		ft_putnbr(x);
		ft_putendl(" valeur x");
		ft_putnbr(i);
		ft_putendl(" valeur i");
		ft_puttab(map);
		//ft_putendl("------------------------------------");

		// ft_putendl(" valeur i");
		// ft_putendl("dans boucle place");
		
		// ft_putstr("valeur de save[i]: ");
		// ft_putchar(save[i]);
		// ft_putendl(" ");
		// ft_putstr("valeur de map[y][x]");
		// ft_putchar(map[y][x]);
		// ft_putendl(" ");
		if (save[i] != '\0' && map[y] && map[y][x] && map[y][x] != '.' && map[y][x] != '\0')
			{
				ft_putendl("dans 1er else if");
	//	sleep(2);
				ft_putendl("------------------------------------");
				ft_putendl("ON ENTRE ICI \n\n\n\n\n\n\n\n");
				return (1);

			}
		else if (save[i] != '\0' && (y > max || x > max))
		{
				ft_putendl("dans 2eme else if");
				ft_putendl("------------------------------------");

	//	sleep(2);
			return (2);
		}
		else if (save[i] == '\n')
		{
			ft_putendl("dans 1er if");
			i++;
			x = coord[1];
			y++;
		}
		else if (save[i] == '.')
		{
			i++;
			x++;
		}
		
		else
		{
			ft_putendl("dans else");
			ft_putendl(&save[i]);
			map[y][x] = save[i];
			i++;
			x++;
		//sleep(2);
		}
		//i++;
		ft_puttab(map);
		ft_putendl("------------------------------------");

		//ft_puttab(map);
		//sleep(2);
	}
	// ft_putendl("fin place");
	return (0);
}


int		**ft_ini_coord(char **save)
{

	int i;
	int **coord;

	i = 0;
	while (save[i] != NULL)
		i++;

	coord = (int **)malloc(sizeof(int *) * i);
	if (!coord)
		return (NULL);
	while (save[--i])
	{		
		coord[i] = (int *)malloc(sizeof(int) * 2);
		if (!coord[i])
			return NULL;
		coord[i][0] = 0;
		coord[i][1] = 0;
	}
	return (coord);
}
