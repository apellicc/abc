/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:00:36 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/05 00:25:57 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	main(int argc, char **argv)
{
	int error;
	char **save;

	if (argc != 2)
		ft_putstr("param invalide\n");
	if (argc != 2)
		return (0);
	save = ft_save(argv[1]);
	ft_putendl("main1");
	error = ft_error(save);
	ft_putendl("main2");
	//if (error != 0)
	//	ft_putstr("error\n");
	//else
	//{
		ft_putendl("avant ft_algo");
		save = ft_algo(save);
		if (!save)
			return 0;
		ft_putendl("main3");
		ft_puttab(save);
		ft_putendl("main4");
	//}
	ft_putnbr(sizeof(void));
	return (0);
}
