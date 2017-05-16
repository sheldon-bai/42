/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:20:43 by xbai              #+#    #+#             */
/*   Updated: 2017/04/10 14:20:46 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ft_error(int errnb)
{
	if (errnb == 9)
		ft_putstr("usage: ./fillit inputfile.\n");
	else if (errnb == 8)
		ft_putstr("failed to open the inputfile.\n");
	else
		ft_putstr("error\n");
	return (0);
}

int		ft_creatlist(t_tetri **cur, t_tetri **tetris, char *buf, char *c)
{
	if (*cur == NULL)
	{
		if ((*cur = ft_gentt(buf, c)) == NULL)
			return (0);
		*tetris = *cur;
		(*c)++;
	}
	else
	{
		if (((*cur)->next = ft_gentt(buf, c)) == NULL)
			return (0);
		(*cur) = (*cur)->next;
		(*c)++;
	}
	return (1);
}

int		ft_reader(int fd, t_tetri **tetris)
{
	char		*buf;
	int			ret;
	t_tetri		*cur;
	int			errnb;
	char		c;

	*tetris = NULL;
	cur = *tetris;
	errnb = 0;
	buf = ft_strnew(BUF_SIZE);
	c = 'A';
	while ((ret = read(fd, buf, BUF_SIZE)) == 21)
	{
		if ((errnb = ft_invalid(buf, ret)))
			return (ft_error(errnb));
		if (ft_creatlist(&cur, tetris, buf, &c) == 0)
			return (0);
	}
	if ((errnb = ft_invalid(buf, ret)))
		return (ft_error(errnb));
	if (ft_creatlist(&cur, tetris, buf, &c) == 0)
		return (0);
	close(fd);
	return ((int)(c - 'A'));
}

int		main(int argc, char **argv)
{
	t_tetri		*tetris;
	int			ttcnt;
	int			fd;

	if (argc != 2)
		return ((int)ft_error(9));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	tetris = NULL;
	ttcnt = ft_reader(fd, &tetris);
	if (ttcnt == 0)
		return (1);
	ft_solve(tetris, ttcnt);
	return (0);
}
