/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 21:12:37 by xbai              #+#    #+#             */
/*   Updated: 2017/04/20 21:00:13 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/libft/includes/libft.h"

# define BUF_SIZE 21

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;
typedef struct		s_tetri
{
	t_point				*first;
	t_point				*second;
	t_point				*third;
	t_point				*forth;
	char				c;
	struct s_tetri		*next;
}					t_tetri;
int					ft_error(int errnb);
int					ft_reader(int fd, t_tetri **tetri);
int					ft_invalid(char *buf, int ret);
t_tetri				*ft_gentt(char *buf, char *c);
void				ft_putlst(t_list *list);
int					ft_checknbr(char *buf);
int					ft_countnbr(char *buf);
void				ft_genpoint(t_tetri *tetri, int count, int i);
void				ft_solve(t_tetri *tetri, int ttcnt);
int					ft_mapsize(int ttcnt);
char				**ft_genmap(int mapsize);
void				ft_putmap(char **map, int mapsize);
void				ft_freemap(char **map, int mapsize);
void				ft_freetetri(t_tetri *tetri);
int					ft_placett(char **map, int mapsize, t_tetri *cur, int i);
void				ft_erasett(char **map, int mapsize, t_tetri *cur, int i);
int					ft_solvemap(char **map, int mapsize, t_tetri *tetri,
								int ttcnt);
int					ft_canplace(char **map, int mapsize, t_tetri *cur, int i);
void				ft_place(char **map, t_tetri *cur, int x, int y);
#endif
