/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:23:52 by esmoreau          #+#    #+#             */
/*   Updated: 2019/02/06 16:47:59 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
** remet des point dans la map si le tetri ne peut pas etre place.
*/

static void		ft_replace_char(char *str, char r, char c)
{
	size_t i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == r)
				str[i] = c;
			i++;
		}
}

/*
** fonction qui alloue et remplit la map de point
*/

static char		*alloc_map(char *map, size_t size)
{
	if (map)
		free(map);
	if (!(map = (char*)malloc(sizeof(char) * (size * size + 1))))
		return (0);
	ft_memset(map, '.', size * size);
	map[size * size] = '\0';
	return (map);
}

/*
** fonction d'affichage
*/

static void		put_tetri(char *str)
{
	int i;
	int v;
	int x;
	int w;

	w = 0;
	i = 0;
	v = 1;
	x = ft_strlen(str);
	while (w * w < x)
		w++;
	while (str[i])
	{
		write(1, &str[i], 1);
		if (v == w)
		{
			v = 0;
			write(1, "\n", 1);
		}
		v++;
		i++;
	}
}

/*
** fonction qui essaye de placer tous les tetri.
** recursive, renvoie 0 si tout n'a pas ete place.
*/

static char		*try(t_var_struct_try var, int size, char **tetris, int t)
{
	int			i;
	char		*temp;

	i = 0;
	while (i < size * size)
	{
		if (check_valid_pos(i, size, tetris[t], var.map))
		{
			var.map = place_tetri(i, size, tetris[t], var.map);
			if (t + 1 == var.count)
				return (var.map);
			temp = try(var, size, tetris, t + 1);
			if (temp)
				return (temp);
			else
				ft_replace_char(var.map, 'A' + t, '.');
		}
		i++;
	}
	return (0);
}

/*
** alloue la map, appelle la recursive.
** si ca ne marche pas, alloue une map plus grande.
*/

int				solve(int count, char **tab, int size)
{
	char				*temp;
	t_var_struct_try	var;

	var.count = count;
	while (size < 20)
	{
		var.map = NULL;
		if (!(var.map = alloc_map(var.map, size)))
			return (0);
		temp = try(var, size, tab, 0);
		if (temp)
		{
			put_tetri(temp);
			free(var.map);
			return (1);
		}
		free(var.map);
		size++;
	}
	return (0);
}
