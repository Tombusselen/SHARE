/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:19:48 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/27 11:41:00 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_nbr(unsigned int n, char *ch)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		ch[i++] = (n % 10) + '0';
		n = n / 10;
		count++;
	}
	while (i > 0)
		write(1, &ch[--i], 1);
	return (count);
}

int	ft_putunsign(int n)
{
	unsigned int	nbr;
	char			ch[50];

	nbr = (unsigned int)n;
	return (write_nbr(nbr, ch));
}
