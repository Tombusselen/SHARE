/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:19:48 by tbussele          #+#    #+#             */
/*   Updated: 2025/06/27 11:40:46 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	write_nbr(int n, int i, char *ch)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count = 1;
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

int	ft_putnbr(int n)
{
	char	ch[11];
	int		i;

	ch[0] = '0';
	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		i = write_nbr(n, i, ch);
	}
	return (i);
}
