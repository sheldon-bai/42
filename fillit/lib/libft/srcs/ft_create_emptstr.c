/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_emptstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbai <xbai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:31:46 by xbai              #+#    #+#             */
/*   Updated: 2017/04/03 19:32:37 by xbai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_create_emptstr(void)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char));
	*ptr = '\0';
	return (ptr);
}