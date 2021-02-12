/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:58:38 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/12 18:14:26 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

char			*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*a;
	unsigned int	len;

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

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			a[len + 1];
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (!s)
		return (0);
	size = ft_strlen(s);
	if ((size_t)start >= size)
		start = size;
	while (i < len)
	{
		a[i] = (s + start)[i];
		i++;
	}
	a[i] = 0;
	return (ft_strdup(a));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	char			*f;
	unsigned int	len1;
	unsigned int	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(f = malloc(len1 + len2 + 1)))
		return (0);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			f[i] = s1[i];
		else
			f[i] = s2[i - len1];
		i++;
	}
	f[i] = 0;
	return (f);
}
