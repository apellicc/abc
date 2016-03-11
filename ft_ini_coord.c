/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:06:34 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/11 03:03:16 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			//coord[nb_piece] = (int *)malloc(sizeof(int) * 2);
			if (!coord[nb_piece])
				return (NULL);
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
