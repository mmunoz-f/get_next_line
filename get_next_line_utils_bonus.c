/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:21:47 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 18:02:38 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*a;

	i = 0;
	len = ft_strlen(s);
	if (!(a = malloc(len + 1)))
		return (0);
	while (i < len)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = 0;
	return (a);
}

char	*ft_substr(char const *src, size_t start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	total;

	if (!src)
		return (0);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	total = ft_strlen(src);
	if (start >= total)
		start = total;
	i = 0;
	src += start;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*result;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (0);
	i = 0;
	len2 = len1 + len2;
	while (i < len2)
	{
		if (i < len1)
			result[i] = s1[i];
		else
			result[i] = s2[i - len1];
		i++;
	}
	result[i] = 0;
	return (result);
}