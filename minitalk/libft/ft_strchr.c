/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:38:16 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/30 15:58:20 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	caract;
	int				i;

	i = 0;
	caract = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == caract)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == caract)
		return ((char *)(&s[i]));
	return (0);
}
