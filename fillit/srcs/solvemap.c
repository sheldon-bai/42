/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:31:55 by xbai              #+#    #+#             */
/*   Updated: 2017/04/15 20:31:58 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ft_mapsize(int ttcnt)
{
	if (ttcnt == 1)
		return (2);
	if (ttcnt == 2)
		return (3);
	if (ttcnt <= 4)
		return (4);
	if (ttcnt <= 6)
		return (5);
	if (ttcnt <= 9)
		return (6);
	if (ttcnt <= 12)
		return (7);
	if (ttcnt <= 16)
		return (8);
	if (ttcnt <= 20)
		return (9);
	if (ttcnt <= 25)
		return (10);
	return (11);
}

char	**ft_genmap(int mapsize)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = (char**)malloc(sizeof(char*) * (mapsize + 1));
	map[mapsize] = NULL;
	while (++i < mapsize)
	{
		j = -1;
		map[i] = (char*)malloc(sizeof(char) * mapsize);
		while (++j < mapsize)
			map[i][j] = '.';
	}
	return (map);
}

void	ft_putmap(char **map, int mapsize)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mapsize)
	{
		j = -1;
		while (++j < mapsize)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}

void	ft_freemap(char **map, int mapsize)
{
	int		i;

	i = -1;
	while (++i < mapsize + 1)
		free(map[i]);
	free(map);
}

int		ft_solvemap(char **map, int mapsize, t_tetri *tetri, int ttcnt)
{
	t_tetri		*cur;
	int			i;

	if (ttcnt == 0)
		return (0);
	cur = tetri;
	i = -1;
	while (++i < mapsize * mapsize)
	{
		if (ft_placett(map, mapsize, cur, i))
		{
			if (!ft_solvemap(map, mapsize, cur->next, ttcnt - 1))
				return (0);
			ft_erasett(map, mapsize, cur, i);
		}
	}
	return (1);
}
