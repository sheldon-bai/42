/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:23:19 by xbai              #+#    #+#             */
/*   Updated: 2017/05/08 23:11:31 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 42
# define FAILCHECKER(x) if (!x) return (-1);

int		get_next_line(const int fd, char **line);
#endif
