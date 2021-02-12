/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:25:58 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/12 10:53:16 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	destroy(char **s)
{
	if (s)
	{
		if (*s)
		{
			free(*s);
			*s = 0;
		}
	}
	return (-1);
}

int	check_rest(char **rest, char **line)
{
	char	*temp;

	if (ft_strchr(*rest, '\n'))
	{
		temp = *rest;
		if (!(*line = ft_substr(*rest, 0, ft_strchr(*rest, '\n') - *rest)))
			return (-1);
		if (!(*rest = ft_strdup(ft_strchr(*rest, '\n') + 1)))
			return (-1);
		free(temp);
		return (0);
	}
	return (1);
}

int	fill_line(int fd, char **rest, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*temp;
	int		x;

	while ((x = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[x] = 0;
		temp = *rest;
		if (!(*rest = ft_strjoin(*rest, buff)))
			return (-1);
		free(temp);
		if (ft_strchr(buff, '\n'))
		{
			temp = *rest;
			if (!(*line = ft_substr(*rest, 0, ft_strchr(*rest, '\n') - *rest)))
				return (-1);
			if (!(*rest = ft_strdup(ft_strchr(buff, '\n') + 1)))
				return (-1);
			free(temp);
			return (1);
		}
	}
	return (x);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest;
	int			x;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(rest))
	{
		if (!(rest = ft_strdup("")))
			return (-1);
	}
	if ((x = check_rest(&rest, line)) == -1)
		return (-1);
	if (!x)
		return (1);
	if ((x = fill_line(fd, &rest, line)) < 0)
		return (destroy(&rest));
	if (!x)
	{
		if (!(*line = ft_strdup(rest)))
			return (-1);
		destroy(&rest);
		return (0);
	}
	return (1);
}
