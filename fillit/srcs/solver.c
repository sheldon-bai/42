/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:31:55 by xbai              #+#    #+#             */
/*   Updated: 2017/04/15 20:31:58 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ft_canplace(char **map, int mapsize,
					t_tetri *cur, int i)
{
	int		x;
	int		y;
	int		xtmp;
	int		ytmp;

	x = i % mapsize;
	y = i / mapsize;
	if (map[y][x] != '.')
		return (0);
	xtmp = x + cur->second->x - cur->first->x;
	ytmp = y + cur->second->y - cur->first->y;
	if (xtmp >= mapsize || ytmp >= mapsize || xtmp < 0 || ytmp < 0
		|| map[ytmp][xtmp] != '.')
		return (0);
	xtmp = x + cur->third->x - cur->first->x;
	ytmp = y + cur->third->y - cur->first->y;
	if (xtmp >= mapsize || ytmp >= mapsize || xtmp < 0 || ytmp < 0
		|| map[ytmp][xtmp] != '.')
		return (0);
	xtmp = x + cur->forth->x - cur->first->x;
	ytmp = y + cur->forth->y - cur->first->y;
	if (xtmp >= mapsize || ytmp >= mapsize || xtmp < 0 || ytmp < 0
		|| map[ytmp][xtmp] != '.')
		return (0);
	return (1);
}

void	ft_place(char **map, t_tetri *cur, int x, int y)
{
	int		xtmp;
	int		ytmp;
	char	c;

	c = cur->c;
	map[y][x] = c;
	xtmp = x + cur->second->x - cur->first->x;
	ytmp = y + cur->second->y - cur->first->y;
	map[ytmp][xtmp] = c;
	xtmp = x + cur->third->x - cur->first->x;
	ytmp = y + cur->third->y - cur->first->y;
	map[ytmp][xtmp] = c;
	xtmp = x + cur->forth->x - cur->first->x;
	ytmp = y + cur->forth->y - cur->first->y;
	map[ytmp][xtmp] = c;
}

int		ft_placett(char **map, int mapsize, t_tetri *cur, int i)
{
	int		x;
	int		y;

	x = i % mapsize;
	y = i / mapsize;
	if (ft_canplace(map, mapsize, cur, i))
	{
		ft_place(map, cur, x, y);
		return (1);
	}
	return (0);
}

void	ft_erasett(char **map, int mapsize, t_tetri *cur, int i)
{
	int		x;
	int		y;
	int		xtmp;
	int		ytmp;

	x = i % mapsize;
	y = i / mapsize;
	map[y][x] = '.';
	ytmp = y + cur->second->y - cur->first->y;
	xtmp = x + cur->second->x - cur->first->x;
	map[ytmp][xtmp] = '.';
	ytmp = y + cur->third->y - cur->first->y;
	xtmp = x + cur->third->x - cur->first->x;
	map[ytmp][xtmp] = '.';
	ytmp = y + cur->forth->y - cur->first->y;
	xtmp = x + cur->forth->x - cur->first->x;
	map[ytmp][xtmp] = '.';
}

void	ft_solve(t_tetri *tetri, int ttcnt)
{
	int		mapsize;
	char	**map;

	mapsize = ft_mapsize(ttcnt);
	map = ft_genmap(mapsize);
	while (ft_solvemap(map, mapsize, tetri, ttcnt))
	{
		ft_freemap(map, mapsize);
		mapsize++;
		map = ft_genmap(mapsize);
	}
	ft_putmap(map, mapsize);
	ft_freetetri(tetri);
}
