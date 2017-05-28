/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:06:43 by xbai              #+#    #+#             */
/*   Updated: 2017/03/28 21:07:29 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (*ss1 && *ss1 == *ss2 && n > 0)
	{
		ss1++;
		ss2++;
		n--;
	}
	if (!n)
		return (0);
	else
		return ((int)(*ss1 - *ss2));
}
