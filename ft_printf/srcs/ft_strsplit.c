/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:55:24 by xbai              #+#    #+#             */
/*   Updated: 2017/04/03 15:55:38 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		split_helper(char **res, int wordcnt, char *start, char c)
{
	int		i;
	int		j;
	char	*end;

	j = 0;
	end = start;
	while (j < wordcnt)
	{
		end = ft_skip_to_delmt(c, end);
		res[j] = (char*)malloc(sizeof(char) * (end - start + 1));
		i = 0;
		while (start < end)
			res[j][i++] = *start++;
		res[j++][i] = '\0';
		start = ft_skip_to_nondelmt(c, start);
		end = start;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	*start;
	char	**res;
	int		wordcnt;

	if (!s || !c)
		wordcnt = 0;
	else
		wordcnt = ft_count_word(s, c);
	start = (char*)s;
	res = (char**)malloc(sizeof(char*) * (wordcnt + 1));
	if (!res)
		return (NULL);
	res[wordcnt] = NULL;
	if (!res)
		return (NULL);
	if (!wordcnt)
		return (res);
	if (*s == c)
		start = ft_skip_to_nondelmt(c, start);
	split_helper(res, wordcnt, start, c);
	return (res);
}
