/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:17:34 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/29 14:38:29 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	nb_chiffre(long n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ch;
	int		i;
	long	nb;

	nb = n;
	i = nb_chiffre(nb);
	ch = malloc(sizeof(char) * (i + 1));
	if (ch == NULL)
		return (0);
	ch[i] = '\0';
	if (nb == 0)
		ch[0] = '0';
	if (nb < 0)
	{
		ch[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		i--;
		ch[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ch);
}
