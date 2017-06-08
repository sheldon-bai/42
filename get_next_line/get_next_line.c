/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:22:33 by xbai              #+#    #+#             */
/*   Updated: 2017/05/08 23:28:04 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strdupuntile(char **line, char *leftover, char c)
{
	int		res;
	int		i;
	int		len;

	res = 0;
	len = ft_strlen(leftover);
	while (leftover[res] != c && res < len)
		res++;
	i = -1;
	FAILCHECKER((*line = (char*)malloc(sizeof(char) * (res + 1))));
	(*line)[res] = '\0';
	while (++i < res)
		(*line)[i] = leftover[i];
	return (res);
}

static char		*ft_rewind(char *leftover, int i)
{
	int		len1;
	int		len2;
	char	*res;
	int		j;

	len1 = ft_strlen(leftover);
	len2 = len1 - i;
	if (!(res = (char*)malloc(sizeof(char) * (len2 + 1))))
		return (NULL);
	res[len2] = '\0';
	j = -1;
	while (++j < len2)
		res[j] = leftover[i + j];
	free(leftover);
	return (res);
}

static t_list	*ft_findfile(t_list **file, int fd)
{
	t_list		*cur;

	cur = *file;
	while (cur)
	{
		if ((int)cur->content_size == fd)
			return (cur);
		cur = cur->next;
	}
	if (!(cur = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(file, cur);
	return (cur);
}

static char		*ft_strjoinfree(char *leftover, char *buf)
{
	char	*tmp;

	tmp = leftover;
	if (!(leftover = ft_strjoin(leftover, buf)))
		return (NULL);
	free(tmp);
	return (leftover);
}

int				get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	int					ret;
	static t_list		*file = NULL;
	char				*leftover;
	t_list				*cur;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	FAILCHECKER((cur = ft_findfile(&file, fd)));
	leftover = (char*)(cur->content);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		FAILCHECKER((leftover = ft_strjoinfree(leftover, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen(leftover))
		return (0);
	if ((ret = ft_strdupuntile(line, leftover, '\n')) < 0)
		return (-1);
	FAILCHECKER((leftover = ft_rewind(leftover, ret + 1)));
	cur->content = leftover;
	return (1);
}
