/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:54:28 by xbai              #+#    #+#             */
/*   Updated: 2017/04/03 15:54:47 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_count_word(char const *s, char c)
{
	int		res;

	res = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			res++;
		else
			break ;
		while (*s && *s != c)
			s++;
	}
	return (res);
}
