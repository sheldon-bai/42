/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:11:35 by xbai              #+#    #+#             */
/*   Updated: 2017/03/27 21:11:48 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s[i] == (char)c)
		return ((char*)(&s[i]));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)(&s[i]));
		i--;
	}
	return (NULL);
}
