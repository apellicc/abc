/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:14:32 by apellicc          #+#    #+#             */
/*   Updated: 2016/02/29 20:00:55 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puttab(char **save)
{
	int	i;

	i = 0;
	ft_putendl("puttab1");
	//ft_putstr(save[i]);
	while (save[i] != NULL)
	{
		ft_putendl(save[i]);
		i++;
	}
}
