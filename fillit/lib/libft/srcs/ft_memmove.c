/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:37:30 by xbai              #+#    #+#             */
/*   Updated: 2017/03/24 16:49:31 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	signed char		fx;
	size_t			idx;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (d > s)
	{
		fx = -1;
		idx = len - 1;
		len = -1;
	}
	else
	{
		fx = 1;
		idx = 0;
	}
	while (idx != len)
	{
		d[idx] = s[idx];
		idx += fx;
	}
	return (dst);
}
