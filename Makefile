NAME	= 	fillit

SOURCE	= 	main.c\
			ft_save.c\
			ft_puttab.c\
			ft_resolve.c\
			ft_error.c\
			ft_mapalloc.c\
			ft_displace.c\
			ft_place_tetri.c\
			ft_ini_coord.c\
			ft_remove.c\
			ft_rp1.c
OBJ		= 	$(SOURCE:.c=.o)

FLAGS	= -Wall -Wextra -Werror -g

CC		=	gcc

INC		=	-I ./ -I ./libft/

all		=	$(NAME)

$(NAME): $(OBJ)
		Make -C ./libft/
		$(CC) $(FLAGS) -o $(NAME) $(SOURCE) $(INC) -L./libft -lft

%.o: %.c
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

all: 	$(NAME)

clean:
		Make -C ./libft/ clean
		rm -rf $(OBJ)

fclean: clean
		Make -C ./libft/ fclean
		rm -rf $(NAME)

re: 	fclean all
