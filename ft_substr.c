/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:00:44 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/01 17:41:42 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	char *ptr;

	if (s == 0)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (0);
	ptr = substr;
	while (len-- && s[start])
		*substr++ = s[start++];
	*substr = 0;
	return (ptr);
}
