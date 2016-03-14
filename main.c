/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 03:30:26 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/12 11:34:23 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**save;
	int		nb_piece;

	if (argc != 2)
		ft_putendl("usage: fillit file");
	if (argc != 2)
		return (0);
	nb_piece = 0;
	save = ft_save(argv[1]);
	if (!save)
		ft_putendl("error");
	else
	{
		nb_piece = ft_tablen(save);
		save = ft_resolve(save, nb_piece);
		if (!save)
			return (0);
		ft_puttab(save);
		ft_free_tab(save);
	}
	return (0);
}
