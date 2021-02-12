/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:21:41 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/12 18:14:57 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(int fd, char **line);

char			*ft_strchr(const char *s, int c);

unsigned int	ft_strlen(const char *s);

char			*ft_strjoin(const char *s1, const char *s2);

char			*ft_strdup(const char *s);

char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
