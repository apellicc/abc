#ifndef FILLIT_H
# define FILLIT_H
# define BUFF 546

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int		main(int argc, char **argv);
char	**ft_save(char *map);
char	**ft_savealloc(char *buff);
char	**ft_cpy(char *buff, char **save);
char	**ft_resolve(char **save, int nbpiece);
int		ft_error(char **save);
int		ft_nbpiece(char *buff);
int		ft_displace(char *save);
char	*ft_replace(char *save, char p);
void	ft_backtrack(char **map, char **save, int **coord, int max);
char	**ft_mapalloc(char **map, int t);
void	ft_remove(char **map, char c);
int		inc_max(int *coord, int max, int i);
int		ft_place_tetri(char **map, char *save, int *coord, int max);
int		**ft_ini_coord(int nb_piece, int **old_coord);
#endif
