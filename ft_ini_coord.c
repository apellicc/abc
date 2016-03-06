#include "fillit.h"

int		**ft_ini_coord(int nb_piece, int **old_coord)
{
	int **coord;

	if (!old_coord)
	{
		coord = (int **)malloc(sizeof(int *) * nb_piece);	
		if (!coord)
			return (NULL);
		while (--nb_piece >= 0)
		{		
			coord[nb_piece] = (int *)malloc(sizeof(int) * 2);
			if (!coord[nb_piece])
				return NULL;
			coord[nb_piece][0] = 0;
			coord[nb_piece][1] = 0;
		}
		return (coord);
	}
	while (--nb_piece >= 0)
		{		
			old_coord[nb_piece][0] = 0;
			old_coord[nb_piece][1] = 0;
		}
	return (old_coord);
}


// int	inc_max(int *coord, int max, int i)
// {
	
// 	if (coord[0] >= max)
// 	{
// 		if (i == 0)
// 		{
// 			return (1);
// 		else
// 			return (2);
// 	}
// 	else if (coord[1] >= max)
// 	{
// 		// ft_putnbr(coord[0]);
// 		ft_putchar('!');
// 		ft_putnbr(coord[1]);
// 		ft_putendl("dans inc ");
// 		coord[0]++;
// 		coord[1] = -1 ;
// 		ft_putnbr(coord[1]);
// 		ft_putendl(" ");
// 	}
// 	return (0);
// }

