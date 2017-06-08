/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:03:23 by xbai              #+#    #+#             */
/*   Updated: 2017/04/03 10:03:56 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*cur;
	t_list		*next;

	if (!alst || !(*alst))
		return ;
	cur = *alst;
	while (cur)
	{
		next = cur->next;
		del(cur->content, cur->content_size);
		free(cur);
		cur = next;
	}
	*alst = NULL;
}
