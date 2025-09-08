/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:33:50 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/03 16:07:38 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

char	*get_next_line(int fd);
//size_t	ft_strlen(const char *str);
//char	*ft_strdup(const char *s);
//char	*ft_strjoin(char const *s1, char const *s2);
//char	*ft_strchr(const char *s, int c);
//char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
