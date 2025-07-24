/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:38:28 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/30 12:07:27 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
	{
		return ((char *)(big));
	}
	while (big[i] != '\0' && i < len)
	{
		while (little[j] && (big[i + j] == little[j]) && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(&big[i]));
		i++;
		j = 0;
	}
	return (NULL);
}
