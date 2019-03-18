/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:36:44 by mamisdra          #+#    #+#             */
/*   Updated: 2019/03/03 17:05:29 by esmoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	error_tab(char **tab_tetri, int j)
{
	tab_tetri[j + 1] = NULL;
	return (0);
}

int			line_to_tab(char **tab_tetri, char *file, int *i, int j)
{
	int tab[2];

	tab[0] = 0;
	tab[1] = -1;
	while (file[*i] && ++tab[1] < 20)
	{
		if (file[*i] == '\n')
		{
			if ((*i - j) % 5 != 4)
				return (error_tab(tab_tetri, j));
			*i = *i + 1;
		}
		else
		{
			if (file[*i] == '#')
				file[*i] = 'A' + j;
			else if (file[*i] != '.')
				return (error_tab(tab_tetri, j));
			tab_tetri[j][tab[0]] = file[*i];
			tab[0]++;
			*i = *i + 1;
		}
	}
	tab_tetri[j][tab[0]] = '\0';
	return (1);
}

int			set_tab(char **tab_tetri, char *file)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (file[++i] && j < 26)
	{
		if (!(tab_tetri[j] = ft_strnew(16)))
			return (error_tab(tab_tetri, j));
		if (line_to_tab(tab_tetri, file, &i, j) == 0)
			return (0);
		if (file[i] == '\0')
			break ;
		if (file[i] != '\n')
			return (error_tab(tab_tetri, j));
		j++;
	}
	tab_tetri[j + 1] = NULL;
	if (file[i - 2] == '\n')
		return (error_tab(tab_tetri, j - 1));
	return (1);
}

char		**ft_read(int fd, char **tab_tetri)
{
	char	buff[650];
	int		ret;
	int		i;

	i = -1;
	if ((ret = read(fd, buff, 650)) <= 0)
	{
		tab_tetri[0] = NULL;
		return (0);
	}
	buff[ret] = '\0';
	if (set_tab(tab_tetri, buff) == 0)
		return (0);
	return (tab_tetri);
}
