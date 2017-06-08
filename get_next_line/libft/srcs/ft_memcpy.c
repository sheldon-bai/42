/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:28:23 by xbai              #+#    #+#             */
/*   Updated: 2017/03/24 16:48:52 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	while (n > 0)
	{
		*dst_temp++ = *src_temp++;
		n--;
	}
	return (dst);
}
