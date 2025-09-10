/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:30:02 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/30 16:10:21 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	size_t			size_total;
	char			*cpy;

	i = 0;
	size_total = size * nmemb;
	cpy = malloc(size_total);
	if (cpy == NULL)
		return (NULL);
	while (i < size_total)
	{
		cpy[i] = 0;
		i++;
	}
	return ((void *)(cpy));
}
