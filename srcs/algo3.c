/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:24:45 by esmoreau          #+#    #+#             */
/*   Updated: 2019/02/06 17:02:02 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		min_size(int count)
{
	int size;

	size = 2;
	while (size * size < count * 4)
		size++;
	return (size);
}

/*
** met le curseur a la fin d'une ligne de la map
*/

int		init_temp(int cursor, int size)
{
	int i;

	while (cursor != size * size)
	{
		i = 0;
		while (i < size)
		{
			i++;
			if (cursor == ((i * size) - 1))
				return (cursor);
		}
		cursor++;
	}
	return (cursor);
}

/*
** fonction qui place un tetri
*/

char	*place_tetri(int curs, int size, char *tetri, char *map)
{
	t_pl_tr v;

	v.quatre = 0;
	v.stop = init_temp(curs, size) - curs + 1;
	v.i = 0;
	v.tmp_cursor = curs;
	if (v.stop >= 4)
		v.stop = 4;
	v.save_stop = v.stop;
	while (v.quatre++ != 4)
	{
		while (v.stop != 0)
		{
			if (tetri[v.i] != '.')
				map[curs] = tetri[v.i];
			curs++;
			v.i++;
			v.stop--;
		}
		v.stop = v.save_stop;
		curs = v.tmp_cursor + size;
		v.tmp_cursor = curs;
		v.i = v.quatre * 4;
	}
	return (map);
}
