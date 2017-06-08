/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:45:33 by xbai              #+#    #+#             */
/*   Updated: 2017/04/03 10:46:27 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*begin;
	t_list		*end;
	t_list		*cur;

	begin = NULL;
	while (lst)
	{
		end = f(lst);
		if (!begin)
		{
			begin = end;
			cur = end;
		}
		else
		{
			cur->next = end;
			cur = cur->next;
		}
		lst = lst->next;
	}
	return (begin);
}
