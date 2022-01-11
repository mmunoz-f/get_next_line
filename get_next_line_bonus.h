/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:03:35 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 18:05:30 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef FD_MAX
#  define FD_MAX 65535
# endif

int		get_next_line(int fd, char **line);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, size_t start, size_t len);

#endif
