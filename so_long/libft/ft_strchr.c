/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:38:16 by tbussele          #+#    #+#             */
/*   Updated: 2025/09/08 12:31:26 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	caract;
	int				i;

	if (s == NULL)
		return (NULL);
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
	return (NULL);
}
