/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:15:34 by tbussele          #+#    #+#             */
/*   Updated: 2025/04/29 13:39:01 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	ch[11];
	int		i;

	ch[0] = '0';
	i = 0;
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n == 0)
		write (fd, "0", 1);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		while (n > 0)
		{
			ch[i++] = (n % 10) + '0';
			n = n / 10;
		}
		while (i > 0)
			write(fd, &ch[--i], 1);
	}
}
