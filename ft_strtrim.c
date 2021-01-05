/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 01:56:48 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/28 01:56:48 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_set(char const *s1, char const *set)
{
	while (*set)
		if (*s1 == *set++)
			return (1);
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t len_s1;
	size_t idx;
	char *trmd_str;

	len_s1 = ft_strlen(s1);
	trmd_str = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (trmd_str == 0)
		return (0);
	ft_memmove(trmd_str, s1, len_s1 + 1);
	idx = 1;
	while (is_set(trmd_str + len_s1 - idx, set))
		*(trmd_str + len_s1 - idx++) = 0;
	idx = 0;
	while (is_set(trmd_str, set))
		ft_memmove(trmd_str, trmd_str + 1, len_s1);
	return (trmd_str);
}
