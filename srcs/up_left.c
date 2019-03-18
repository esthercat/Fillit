/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:25:29 by esmoreau          #+#    #+#             */
/*   Updated: 2019/01/30 16:43:32 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	up_line(char *str, int i)
{
	char c[2];

	c[0] = 'A' + i;
	c[1] = '\0';
	while (!ft_strnstr(str, c, 4))
	{
		ft_memmove(str, str + 4, 12);
		ft_memset(str + 12, '.', 4);
	}
}

static void	left_col(char *str, int i)
{
	while (str[0] != 'A' + i && str[4] != 'A' + i && str[8] != 'A' + i
			&& str[12] != 'A' + i)
	{
		ft_memmove(str, str + 1, 3);
		str[3] = '.';
		ft_memmove(str + 4, str + 5, 3);
		str[7] = '.';
		ft_memmove(str + 8, str + 9, 3);
		str[11] = '.';
		ft_memmove(str + 12, str + 13, 3);
		str[15] = '.';
	}
}

void		up_left(char **tab, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		up_line(tab[i], i);
		left_col(tab[i], i);
		i++;
	}
}
