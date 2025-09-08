/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:47:43 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/30 15:03:44 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int searched, size_t size)
{
	unsigned int	i;
	unsigned char	s;
	unsigned char	*char_mem;

	char_mem = (unsigned char *)mem;
	s = (unsigned char)searched;
	i = 0;
	while (i < size)
	{
		if (char_mem[i] == s)
			return ((void *)(&char_mem[i]));
		i++;
	}
	return (NULL);
}
