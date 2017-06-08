/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:22:59 by xbai              #+#    #+#             */
/*   Updated: 2017/04/03 19:32:48 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strtrim(char const *s)
{
	int		len;
	int		start;
	int		end;
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (!(len = ft_strlen(s)))
		return (ft_create_emptstr());
	start = 0;
	end = len - 1;
	while (start < len && ft_isspace(s[start]))
		start++;
	while (end >= 0 && ft_isspace(s[end]))
		end--;
	if (end < start)
		return (ft_create_emptstr());
	if (!(res = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (start <= end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
