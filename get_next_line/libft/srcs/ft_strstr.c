/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:23:12 by xbai              #+#    #+#             */
/*   Updated: 2017/03/27 21:23:27 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	if (*little)
	{
		while (big[i])
		{
			j = 0;
			while (big[i + j] == little[j] && little[j])
				j++;
			if (!little[j])
				return ((char*)(&big[i]));
			i++;
		}
		return (NULL);
	}
	return ((char*)(big));
}
