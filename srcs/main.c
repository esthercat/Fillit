/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmoreau <esmoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:24:26 by esmoreau          #+#    #+#             */
/*   Updated: 2019/03/01 18:54:03 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <stdio.h>

static void	ft_free(char **tab_tetri)
{
	int	i;

	i = -1;
	while (tab_tetri[++i])
		free(tab_tetri[i]);
	free(tab_tetri);
}

static int	ft_core(char **av)
{
	int		fd;
	char	**tab_tetri;
	int		nbr;
	int		i;

	i = -1;
	if (!(tab_tetri = (char **)malloc(sizeof(char *) * 27)))
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == 0)
	{
		free(tab_tetri);
		return (0);
	}
	if (ft_read(fd, tab_tetri) == 0
		|| (nbr = check_valid_file(tab_tetri)) == 0)
	{
		ft_free(tab_tetri);
		return (0);
	}
	up_left(tab_tetri, nbr);
	solve(nbr, tab_tetri, min_size(nbr));
	ft_free(tab_tetri);
	close(fd);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fillit source_file");
		return (0);
	}
	if (ft_core(argv) == 0)
		ft_putendl("error");
	return (0);
}
