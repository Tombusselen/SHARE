/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:11:15 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/30 13:04:02 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned int		i;
	unsigned char		*char_dest;
	unsigned const char	*char_src;

	if (!dest && !src)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned const char *)src;
	if (char_dest < char_src)
	{
		i = 0;
		while (i < size)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	else
	{
		i = size;
		while (i-- > 0)
			char_dest[i] = char_src[i];
	}
	return (dest);
}
