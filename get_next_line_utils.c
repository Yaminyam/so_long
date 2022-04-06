/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:01:41 by sikang            #+#    #+#             */
/*   Updated: 2021/08/18 07:35:55 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;

	if (s == 0)
		return (0);
	t = (char *)s;
	while (*t)
	{
		if (*t == (char)c)
			return (t);
		t++;
	}
	if (*t == (char)c)
		return (t);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;

	cnt = ft_strlen(src);
	while (dstsize > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	if (dstsize)
		*dst = '\0';
	return (cnt);
}

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	char	*str;

	n = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(n + 1);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free((void *)s1);
	return (str);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(n + 1);
	if (str == 0)
		return (0);
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
