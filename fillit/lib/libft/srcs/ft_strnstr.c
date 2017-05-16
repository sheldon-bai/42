/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 22:05:05 by xbai              #+#    #+#             */
/*   Updated: 2017/03/27 22:06:52 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	int		n;
	int		len_little;

	len_little = ft_strlen(little);
	n = (int)len;
	if (!len_little)
		return ((char*)(big));
	i = 0;
	while (big[i] && n >= len_little)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (!little[j])
			return ((char*)(&big[i]));
		n--;
		i++;
	}
	return (NULL);
}
