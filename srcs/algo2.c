/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:25:09 by esmoreau          #+#    #+#             */
/*   Updated: 2019/02/06 16:46:45 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
** prepare la structure pour la prochaine ligne du tetri
*/

static t_variable	next_line(t_variable var, int size, int curs, int k)
{
	while (var.cursor != var.temp_cursor || var.i != var.temp_i)
	{
		if (var.cursor != var.temp_cursor)
			var.cursor++;
		if (var.i != var.temp_i)
			var.i++;
	}
	while (var.cursor != curs + size * k)
		var.cursor++;
	var.i++;
	var.temp_cursor += size;
	var.temp_i += 4;
	return (var);
}

/*
** verifie si on peut placer le tetri dans la map.
*/

int					check_valid_pos(int curs, int size, char *tetri, char *map)
{
	t_variable	var;
	int			k;

	var.i = 0;
	var.nbdiez = 0;
	var.cursor = curs;
	var.temp_cursor = init_temp(var.cursor, size);
	var.temp_i = 3;
	k = 1;
	while (tetri[var.i] && map[var.cursor])
	{
		while (tetri[var.i] && map[var.cursor]
				&& var.i != var.temp_i && var.cursor != var.temp_cursor)
		{
			if (tetri[var.i] != '.' && map[var.cursor] == '.')
				var.nbdiez++;
			var.i++;
			var.cursor++;
		}
		if (tetri[var.i] != '.' && map[var.cursor] == '.')
			var.nbdiez++;
		var = next_line(var, size, curs, k);
		k++;
	}
	return ((var.nbdiez == 4) ? 1 : 0);
}
