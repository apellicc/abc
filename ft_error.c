/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:27:38 by apellicc          #+#    #+#             */
/*   Updated: 2016/02/28 19:17:13 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_error(char *buff, int r)
{
	int error;
	ft_putendl("dans error");
	(void)buff;
	(void)r;
	error = 1;
	return (error);
}
