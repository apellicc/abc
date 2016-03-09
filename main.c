/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 03:30:26 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/06 03:30:30 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		error;
	char	**save;
	int		nb_piece;

	if (argc != 2)
		ft_putendl("usage: fillit file");
	if (argc != 2)
		return (0);
	save = ft_save(argv[1]);
	nb_piece = ft_tablen(save);
	error = ft_error(save);
	if (error != 0)
		ft_putendl("error");
	else
	{
		save = ft_resolve(save, nb_piece);
		if (!save)
			return (0);
	}
	ft_puttab(save);
	ft_free_tab(save);
	return (0);
}
