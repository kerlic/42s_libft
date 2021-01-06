/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:36:17 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/06 19:58:17 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_set(char const *s1, char const *set)
{
	while (*set)
		if (*s1 == *set++)
			return (1);
	return (0);
}

static	size_t	ft_trmlen(char const *s1, char const *set)
{
	char	const	*start;
	char	const	*end;

	while (is_set(s1++, set))
		;
	start = s1 - 1;
	while (*s1)
		s1++;
	while (is_set(--s1, set))
		;
	end = s1;
	return ((size_t)(end - start));
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		len_s1;
	char		*trmd_str;

	len_s1 = ft_trmlen(s1, set);
	if (!(trmd_str = (char *)malloc(sizeof(char) * (len_s1 + 2))))
		return (0);
	while (is_set(s1, set))
		++s1;
	ft_memmove(trmd_str, s1, len_s1 + 1);
	trmd_str[len_s1 + 1] = 0;
	return (trmd_str);
}
