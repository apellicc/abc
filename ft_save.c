/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:06:04 by apellicc          #+#    #+#             */
/*   Updated: 2016/03/04 02:27:49 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_save(char *map)
{
	int		fd;
	char	*buff;
	char	**save;
	int		r;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buff = ft_memalloc(600);
	r = read(fd, buff, BUFF);
	close(fd);
	if (ft_error(buff, r) == 0)
		return (NULL);
	ft_putendl("avant savalloc");
	save = ft_savealloc(buff);

	if (!save)
		return (NULL);
	ft_putendl("avant cpy");
	save = ft_cpy(buff, save);
	free(buff);
	if(!save[0] && !save[0][0])
		ft_putendl("niaue ta rqce");
	ft_putendl("avant cpy");

	fd = -1;
	while (save[++fd] != NULL)
		save[fd] = ft_replace(save[fd], fd + 65);
		ft_putendl("fin save");

	return (save);
}

char	*ft_replace(char *save, char p)
{
	int i;
	int i1;

	i = 0;
	i1 = 0;
	ft_putendl("avant displace");
	if (save[0] != '#')
		i1 = ft_displace(save);
	ft_putendl("apres diplace");
	while (save[i] != '\0')
	{
		if (save[i] == '#')
		{
			save[i] = '.';
			save[i - i1] = p;
		}
		i++;
	}
	ft_putendl("fin replace");
	return (save);
}

char	**ft_savealloc(char *buff)
{
	int		i;
	int		i1;
	char	**save;

	i = ft_nbpiece(buff);
	if (i == -1)
		return (NULL);
	i1 = ft_strlen(buff);
	if (i1 != (i * 20) + (i - 1))
		return (NULL);
	else
	{
		if (!(save = (char **)malloc(sizeof(char *) * (i + 1))))
			return (NULL);
	}
	i1 = -1;
	while (++i1 < i)
	{
		if (!(save[i1] = (char *)malloc(21)))
			return (NULL);
	}
	save[i1] = NULL;
	return (save);
}

int		ft_nbpiece(char *buff)
{
	int		i;
	int		i1;

	i1 = 0;
	i = 0;
	while (buff[i] != '\0')
	{
		if ((buff[i] == '\n' && buff[i + 1] == '\n') || buff[i + 1] == '\0')
		{
			if (buff[i + 1] == '\n' && (buff[i + 2] == '\n'
				|| buff[i + 2] == '\0'))
				return (-1);
			i1++;
		}
		i++;
	}
	return (i1);
}

char	**ft_cpy(char *buff, char **save)
{
	int		b;
	int		s;
	int		s1;

	b = 0;
	s = 0;
	s1 = 0;
	while (buff[b] != '\0')
	{
		save[s][s1] = buff[b];
		if (buff[b] == '\n' && buff[b + 1] == '\n')
		{
			save[s][s1] = '\0';
			s++;
			s1 = -1;
			b++;
		}
		b++;
		s1++;
	}
	save[s + 1] = NULL;
	save[s][s1] = '\0';
	return (save);
}
