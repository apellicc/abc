/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 10:29:44 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/09 10:50:53 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_remove(char **map, char c)
{
	int x;
	int y;

	y = -1;
	while (map[++y])
	{
		//ft_putnbr(y);
		//ft_putendl("valeur de y dans remove");

		x = -1;
		while (map[y][++x])
		{
		//	ft_putnbr(x);
		//	ft_putendl("valeur de x");
			if (map[y][x] == c)
				map[y][x] = '.';
		}
	}
	//ft_putendl("apres remove");
}
