/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:27:38 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/14 01:49:07 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int maft(char *s, int x)
{
    int i;
    int countpoint;
    int countcrx;
    countpoint = 0;
    countcrx = 0;
    i = 0;
    while (i < 21)
    {
        if (s[x + i] == '.')
            countpoint++;
        if (s[x + i] == '#')
            countcrx++;
        if ((i % 5) == 0 && s[x + i] != '\n')
            return(0);
        i++;
    }
    if(countpoint != 12 || countcrx != 4)
        return (0);
    return (1);
}
int ft_error(char *s, int r)
{
    int     i;
    i = 20;
	if (r > 546)
		return (0);
    if((ft_strlen(s) % 23) != 0)
        return (0);
    while(s[i])
    {
        if((s[i] != '\n' && s[i] != '\0') || maft(s, i) == 0)
        {
			free(s);
            return (0);
        }
		if (s[i + 21])
			i += 21;
    }
    return(1);
}
