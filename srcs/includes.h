/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:24:03 by esmoreau          #+#    #+#             */
/*   Updated: 2019/03/01 18:45:10 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"

typedef struct		s_variable
{
	int i;
	int temp_cursor;
	int temp_i;
	int nbdiez;
	int cursor;
}					t_variable;

typedef struct		s_pl_tr
{
	int tmp_cursor;
	int quatre;
	int stop;
	int save_stop;
	int i;
}					t_pl_tr;

typedef struct		s_var_struct_try
{
	int		count;
	char	*map;
}					t_var_struct_try;

int					check_valid_file(char **tet);
void				up_left(char **tab, int count);
int					solve(int count, char **tab, int size);
int					min_size(int n);
int					init_temp(int cursor, int size);
int					check_valid_pos(int curs, int size, char *tetri, char *map);
char				*place_tetri(int pos, int taille_map, char *tetri,
					char *map);
char				**ft_read(int fd, char **tab_tetri);
#endif
