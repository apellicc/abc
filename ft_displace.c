/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 03:27:25 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/17 11:11:05 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_line(char *save)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (save[i] != '#')
	{
		if (save[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

int				ft_displace(char *save)
{
	int	i;
	int	i1;
	int	tmp;

	i = 0;
	i1 = 19;
	while (save[i] != '\0')
	{
		if (i == 0 || save[i] == '\n')
			tmp = 0;
		if (save[i] == '#' && tmp - 1 < i1)
		{
			i1 = tmp - 1;
			if (i < 5)
				i1++;
		}
		i++;
		tmp++;
	}
	tmp = ft_line(save);
	return (i1 + (tmp * 5));
}
