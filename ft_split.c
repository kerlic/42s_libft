/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 04:25:57 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/28 04:25:57 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char* ft_subarray(char const* s, char c)
{
	int		cnt;
	char* subarr;
	char* ptr;

	cnt = 0;
	while (s[cnt] != c && s[cnt])
		cnt++;
	if (!(subarr = (char*)malloc(sizeof(char) * (cnt + 1))))
		return (0);
	ptr = subarr;
	while (cnt--)
		*subarr++ = *s++;
	*subarr = 0;
	return (ptr);
}

char	**ft_split(char const* s, char c)
{
	int		idx;
	int		cnt;
	char	**str;

	idx = 0;
	cnt = 0;
	while (s[idx])
		if (s[idx++] == c)
			cnt++;
	if (!(str = (char**)malloc(sizeof(char*) * (cnt + 2))))
		return (0);
	idx = 0;
	if (*s != c && *s)
		if (!(str[idx++] = ft_subarray(s++, c)))
			while (--idx >= 0)
				free(str[idx]);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != 0)
			str[idx++] = ft_subarray(s, c);
		s++;
	}
	str[idx] = 0;
	return (str);
}
