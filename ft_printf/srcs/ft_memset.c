/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:21:43 by xbai              #+#    #+#             */
/*   Updated: 2017/03/24 16:53:23 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp;

	tmp = (unsigned char*)b;
	while (len-- > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
	}
	return (b);
}
