/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:29:42 by xbai              #+#    #+#             */
/*   Updated: 2017/03/29 09:29:53 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	char				*s;
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	s = (char*)str;
	while (ft_isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	s = (*s == '-' || *s == '+') ? s + 1 : s;
	while (*s == '0')
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			res = res * 10 + (*s - '0');
		else
			break ;
		s++;
	}
	if (res >= 1ULL << 63)
		return (sign == 1 ? -1 : 0);
	return ((int)(res * sign));
}
