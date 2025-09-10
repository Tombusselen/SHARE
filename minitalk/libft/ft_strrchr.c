/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:33:31 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/30 15:57:43 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	caract;
	int				i;
	int				j;

	i = 0;
	j = 0;
	caract = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == caract)
			j = i;
		i++;
	}
	if (s[i] == caract)
		return ((char *)(&s[i]));
	else if (s[j] == caract)
		return ((char *)(&s[j]));
	return (NULL);
}
