/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:15:06 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/05 22:00:58 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char		*tmp;
	const char	*s;

	tmp = dest;
	s = src;
	if (dest <= src)
	{
		while (count--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += count;
		s += count;
		while (count--)
			*--tmp = *--s;
	}
	return (dest);
}
