/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:25:00 by esmoreau          #+#    #+#             */
/*   Updated: 2019/02/06 15:49:24 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_check(char **tet, int i, int j)
{
	int	touch;

	touch = 0;
	if (j < 16 && tet[i][j + 1] == 'A' + i)
		touch++;
	if (j > 0 && tet[i][j - 1] == 'A' + i)
		touch++;
	if (j <= 12 && tet[i][j + 4] == 'A' + i)
		touch++;
	if (j >= 4 && tet[i][j - 4] == 'A' + i)
		touch++;
	return (touch);
}

static int	check_tetri(char **tet, int i, int *nb_block, int *touch)
{
	int	j;

	j = 0;
	while (tet[i][j])
	{
		if (tet[i][j] != '.' && tet[i][j] != 'A' + i)
			return (0);
		if (tet[i][j] == 'A' + i)
		{
			*touch = *touch + ft_check(tet, i, j);
			*nb_block = *nb_block + 1;
		}
		j++;
	}
	return (1);
}

int			check_valid_file(char **tet)
{
	int	i;
	int	touch;
	int	nb_block;

	i = 0;
	while (tet[i])
	{
		touch = 0;
		nb_block = 0;
		if (ft_strlen(tet[i]) != 16)
			return (0);
		if ((check_tetri(tet, i, &nb_block, &touch)) == 0)
			return (0);
		if (nb_block != 4 || touch < 6 || i > 25)
			return (0);
		i++;
	}
	return (i);
}
