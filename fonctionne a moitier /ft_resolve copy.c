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
	ft_backtrack(map, save, coord, qrt - 1);

	//ft_free_tab(save);
	while (nb_piece)
	{
		free(coord[nb_piece]);
		nb_piece--;
	}
	free(coord);
	return (map);
}

void	ft_backtrack(char **map, char **save, int **coord, int max)
{
	int i;
	int rp;

	i = 0;
	while (save[i] != NULL)
	{
		ft_putnbr(i);
		ft_putendl("valeur de i");
		rp = ft_place_tetri(map, save[i], coord[i], max);	
		ft_putnbr(rp);
		ft_puttab(map);
		ft_putendl("valeur de rp");

		if (rp != 0)
			ft_remove(map, 'A' + i);
		if (rp == 1)
		{
			ft_putendl("avant if ")
			if (coord[i][0] == max && i == 0)
			{
				ft_putendl("elelel");
				coord = ft_ini_coord(ft_tablen(save), coord);
				max++;
				ft_putnbr(max);
				ft_putendl("valeur de max");
				map = ft_mapalloc(map, max);
			}
			else 
			{
				ft_putendl("dans else");
//				ft_remove(map, 'A' + i);
				coord[i][0] = 0;
				coord[i][1] = 0;
				i--;
				ft_remove(map, 'A' + i);

				coord[i][1]++;
				
			}
		}
		else if (rp == 2)
		{
			coord[i][1]++;
			if (coord[i][1] >= max)
			{
				coord[i][0]++;
				coord[i][1] = 0;
			}

		}
		else
			i++;
	}
}
