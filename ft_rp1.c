/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rp1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 21:01:56 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/10 22:53:06 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_rp1(int **coord, int *max, int *i, char **map)
{
	coord[*i][0] = 0;
	coord[*i][1] = 0;
	if (*i == 0)
	{
		*max += 1;
		map = ft_mapalloc(map, *max);
	}
	else
	{
		*i -= 1;
		ft_remove(map, 'A' + *i);
		coord[*i][1] += 1;
	}
	return (map);
}
