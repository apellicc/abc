/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:32:27 by gmorer            #+#    #+#             */
/*   Updated: 2016/03/21 17:14:35 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		countlink(char *s, int i, int x)
{
	int	link;

	link = 0;
	if (x > 0 && s[i + x - 1] == '#')
		link++;
	if (s[i + x + 1] == '#')
		link++;
	if (x < 15 && s[i + x + 5] == '#')
		link++;
	if (x >= 5 && s[i + x - 5] == '#')
		link++;
	return (link);
}

static int		checkjoin(char *s, int i)
{
	int	crx;
	int	x;
	int	rslt;
	int	pnt;

	x = 0;
	rslt = 0;
	crx = 0;
	pnt = 0;
	while (s[i + x] && x < 21)
	{
		(s[i + x] == '.') ? pnt++ : 0;
		if (s[i + x] == '#')
			rslt += countlink(s, i, x);
		if (s[i + x] == '#')
			crx++;
		x++;
	}
	if (crx != 4 || pnt != 12)
		return (-1);
	return (rslt - 6);
}

static int		maft(char *s, int x)
{
	int	i;
	int	countpoint;
	int	countcrx;

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
			return (0);
		i++;
	}
	if (countpoint != 12 || countcrx != 4)
		return (0);
	return (1);
}

int				ft_error(char *s, int r)
{
	int	i;

	i = 0;
	if (r > 546 || checkjoin(s, 0) < 0)
		return (0);
	while (s[i])
	{
		if (i != 0 && ((s[i] != '\n' && s[i] != '\0') || maft(s, i) == 0 ||
					checkjoin(s, i) < 0))
		{
			if (s[i + 1] == '\0')
				return (1);
			return (0);
		}
		if ((s[i + 21]) && i != 0)
			i += 21;
		else if ((s[i + 19]))
			i += 20;
		else
			return (0);
	}
	return (1);
}
