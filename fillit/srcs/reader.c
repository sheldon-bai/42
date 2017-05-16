/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:31:48 by xbai              #+#    #+#             */
/*   Updated: 2017/04/15 20:31:50 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int			ft_invalid(char *buf, int ret)
{
	int		i;
	int		ht_cnt;

	i = -1;
	ht_cnt = 0;
	if (ret != 21 && ret != 20)
		return (6);
	if (ret == 21 && buf[20] != '\n')
		return (7);
	while (++i < 20)
	{
		if (i % 5 < 4 && buf[i] != '#' && buf[i] != '.')
			return (1);
		if (i % 5 == 4 && buf[i] != '\n')
			return (2);
		ht_cnt += (buf[i] == '#');
		if (ht_cnt > 4)
			return (3);
	}
	if (ht_cnt != 4)
		return (4);
	return (0);
}

void		ft_genpoint(t_tetri *tetri, int count, int i)
{
	t_point		*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = i % 5;
	point->y = i / 5;
	if (count == 0)
		tetri->first = point;
	else if (count == 1)
		tetri->second = point;
	else if (count == 2)
		tetri->third = point;
	else
		tetri->forth = point;
}

t_tetri		*ft_gentt(char *buf, char *c)
{
	int			i;
	int			count;
	t_tetri		*tetri;

	if (ft_checknbr(buf))
		return (NULL);
	i = 0;
	count = 0;
	tetri = (t_tetri*)malloc(sizeof(t_tetri));
	tetri->next = NULL;
	tetri->c = *c;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			ft_genpoint(tetri, count, i);
			count++;
		}
		i++;
	}
	return (tetri);
}

void		ft_putlst(t_list *list)
{
	char	*content;

	content = list->content;
	ft_putstr(content);
}

void		ft_freetetri(t_tetri *tetri)
{
	t_tetri		*next;

	while (tetri != NULL)
	{
		next = tetri->next;
		free(tetri->first);
		free(tetri->second);
		free(tetri->third);
		free(tetri->forth);
		free(tetri);
		tetri = next;
	}
}
