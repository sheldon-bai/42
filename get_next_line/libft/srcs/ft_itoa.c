/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 21:01:05 by xbai              #+#    #+#             */
/*   Updated: 2017/04/03 16:01:57 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*ft_itoa_helper(int n, char *digits)
{
	char	*res;
	int		len;
	int		i;

	len = ft_nlen(n);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = (n < 0) ? 1 : 0;
	*res = (n < 0) ? '-' : '+';
	n = (n < 0) ? -n : n;
	while (n)
	{
		if (*res == '-')
			res[len - i] = digits[n % 10];
		else
			res[len - i - 1] = digits[n % 10];
		n /= 10;
		i++;
	}
	res[len] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	char	*digits;

	digits = ft_strdup("0123456789");
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_itoa_helper(n, digits));
}
