/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_neighbor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:31:36 by xbai              #+#    #+#             */
/*   Updated: 2017/04/15 20:31:39 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ft_countnbr(char *buf)
{
	int		col;
	int		row;
	int		i;
	int		ht_cnt;

	i = -1;
	ht_cnt = 0;
	while (++i < 20)
	{
		row = i / 5;
		col = i % 5;
		if (buf[i] == '#')
		{
			if (row - 1 >= 0 && buf[i - 5] == '#')
				ht_cnt++;
			if (row + 1 < 4 && buf[i + 5] == '#')
				ht_cnt++;
			if (col - 1 >= 0 && buf[i - 1] == '#')
				ht_cnt++;
			if (col + 1 < 4 && buf[i + 1] == '#')
				ht_cnt++;
		}
	}
	return (ht_cnt);
}

int		ft_checknbr(char *buf)
{
	int			nb;

	nb = ft_countnbr(buf);
	if (nb == 6 || nb == 8)
		return (0);
	else
		nb = ft_error(5);
	return (1);
}
